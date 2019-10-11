 #!/usr/bin/env bash

 # Execute this file to install the titancoin cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Titancoin-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Titancoin-Qt.app/Contents/MacOS/titancoind /usr/local/bin/titancoind
 sudo ln -s ${LOCATION}/Titancoin-Qt.app/Contents/MacOS/titancoin-cli /usr/local/bin/titancoin-cli
