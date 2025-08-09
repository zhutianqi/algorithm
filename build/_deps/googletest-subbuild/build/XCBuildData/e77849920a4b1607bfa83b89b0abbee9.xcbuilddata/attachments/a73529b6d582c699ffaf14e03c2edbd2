#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/tianqizhu/algorithm/build/_deps
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/download-googletest-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/verify-googletest-populate.cmake
  /opt/homebrew/bin/cmake -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/extract-googletest-populate.cmake
  /opt/homebrew/bin/cmake -E touch /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/googletest-populate-download
fi

