INSTALL_PREFIX="`pwd`/boost"
DYNAMIC_LIB_DIR="$INSTALL_PREFIX/dylib"

if [ ! -d "$INSTALL_PREFIX" ]; then
	mkdir "$INSTALL_PREFIX"
fi

pushd ../Boost-For-Mobile/boost/
 	./bootstrap.sh --with-libraries=filesystem --prefix="$INSTALL_PREFIX"
	./b2 install
popd

if [ ! -d "$DYNAMIC_LIB_DIR" ]; then
	mkdir "$DYNAMIC_LIB_DIR"
fi

#####################################################################################
# move the dynamic libraries to another directory, Xcode gets confused when having  #
# static and dynamic libraries in the same directory.
#####################################################################################

pushd "$INSTALL_PREFIX/lib"
	for f in *.dylib ; do
		mv $f "$DYNAMIC_LIB_DIR"
	done
popd