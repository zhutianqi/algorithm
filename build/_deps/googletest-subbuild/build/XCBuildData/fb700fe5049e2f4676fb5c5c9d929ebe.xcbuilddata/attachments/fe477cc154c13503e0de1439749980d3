#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild
  /opt/homebrew/bin/cmake -Dcfgdir=/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp/googletest-populate-mkdirs.cmake
  /opt/homebrew/bin/cmake -E touch /Users/tianqizhu/algorithm/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/googletest-populate-mkdir
fi

