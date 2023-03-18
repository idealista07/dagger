#!/bin/sh

if [ ! -d "cross" ] ; then mkdir cross ; fi

cd cross
mkdir dest dest/bin

export gcc_checksum="e9e857bd81bf7a370307d6848c81b2f5403db8c7b5207f54bce3f3faac3bde63445684092c2bc1a2427cddb6f7746496d9fbbef05fbbd77f2810b2998f1f9173  gcc-12.2.0.tar.xz"
export bin_checksum="a37e042523bc46494d99d5637c3f3d8f9956d9477b748b3b1f6d7dfbb8d968ed52c932e88a4e946c6f77b8f48f1e1b360ca54c3d298f17193f3b4963472f6925  binutils-2.40.tar.xz"

if [ ! -f "gcc-12.2.0.tar.xz" ] ; then
	wget https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.xz
fi

if [ ! -f "gcc-12.2.0.tar.xz" ] ; then
	echo "error downloading gcc"
	exit
fi

if [ ! "$(sha512sum gcc-12.2.0.tar.xz)" = "$gcc_checksum" ] ; then
	echo "gcc checksum failed"
	exit
fi

if [ ! -f "binutils-2.40.tar.xz" ] ; then	
	wget https://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.xz
fi


if [ ! -f "binutils-2.40.tar.xz" ] ; then	
	echo "Error downloading binutils"
	exit
fi

if [ ! "$(sha512sum binutils-2.40.tar.xz)" = "$bin_checksum" ] ; then
	echo "binutils checksum failed"
	exit
fi
