#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild
  /opt/homebrew/bin/cmake -E echo_append
  /opt/homebrew/bin/cmake -E touch /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/googletest-populate-update
fi

