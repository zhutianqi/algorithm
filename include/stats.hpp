//
//  types.hpp
//  algorithm
//
//  Created by Tianqi Zhu on 8/8/25.
//

#pragma once
#include <cmath>     // sqrt, erf
#include <vector>    // vector
#include <numeric>   // accumulate
#include <stdexcept> // invalid_argument
#include <algorithm>

namespace stats {

    // Distribution
    struct Dist {
        double mu  = 0.0;
        double sigma = 0.0; 
    };

    // φ(z)
    inline double psi(double z) {
        static const double inv_sqrt_2pi = 0.3989422804014327; // 1/sqrt(2*pi)
        return inv_sqrt_2pi * std::exp(-0.5 * z * z);
    }

    // Φ(z)
    inline double phi(double z) {
        // 0.5 * (1 + erf(z / sqrt(2)))
        return 0.5 * (1.0 + std::erf(z / std::sqrt(2.0)));
    }

    // N(mu, sigma^2) 的下尾概率：P(X < a)
    inline double normal_head_prob(double mu, double sigma, double a) { 
        // no protection
        if (sigma <= 0) return mu < a ? 1.0 : (mu == a ? 0.5 : 0.0);
        return phi((a - mu) / sigma);
    }

    //  N(mu, sigma^2) 的上尾概率：P(X > a)
    inline double normal_tail_prob(double mu, double sigma, double a) { 
        // no protection
        if (sigma <= 0) return mu < a ? 0.0 : (mu == a ? 0.5 : 1.0);
        return phi((mu - a) / sigma);
    }



    
    // CLT
    Dist clt_iid_params_sigma(double mu, double sigma, double scale);
    double clt_iid_prob_less(double mu, double sigma, double scale, double a);
    Dist clt_ind_params_sigma(const std::vector<Dist>& dists);
    double clt_ind_prob_less(const std::vector<Dist>& dists, double a);
    
}