#!/bin/sh

if [ -z "$TRAVIS_OS_NAME" ]; then
    TRAVIS_OS_NAME=linux
fi

if [ "$TRAVIS_OS_NAME" = "linux" ]; then
	if [ "$GCC_VERSION" ]; then
		echo 'Setting up protobuf...';
		if [ ! -d "$HOME/protobuf/lib" ]; then
			cd tools/protobuf
			./autogen.sh
			./configure --prefix=$HOME/protobuf > nul
			make
			make install
		
			cd ../../
		else
	  		echo 'Using cached protobuf directory.';
		fi
	fi
	
	wget http://downloads.sourceforge.net/ltp/lcov-1.12.tar.gz
	tar -xf lcov-1.12.tar.gz
	cd lcov-1.12
	make install

	cd ..
	gem install coveralls-lcov
    
	mkdir 3rdParty
	mkdir 3rdParty/include
	mkdir 3rdParty/lib
else
    echo "Unknown OS ($TRAVIS_OS_NAME). Stopping build ..."
    exit 1
fi
