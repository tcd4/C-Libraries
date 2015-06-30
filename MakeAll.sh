#!/bin/bash
# This script compiles all the libraries in CLibs


echo "#####Building CLibs libraries.#####"

MakeAll()
{
    echo "##### Building Types Library. #####"
    cd types
    make
    make static
    cd ../

    for d in utils/*/
    do
	name=${d}
	name=${name#utils/}
	name=${name%/}

	echo "##### Building ${name} Library. #####"
	cd ${d}
	make
	make static
	cd ../..
    done
}

MakeAll

