#!/bin/bash
# This scripts cleans all the libraries in CLibs


echo "#####Cleaning CLibs Libraries.#####"

CleanAll()
{
    echo "##### Cleaning Types Library. #####"
    cd types
    make clean
    cd ..

    for d in utils/*/
    do
	name=${d}
	name=${name#src/}
	name=${name%/}

	echo "#####Cleaning ${name} library.#####"

	cd ${d}
	make clean
	cd ../..
    done
}

CleanAll

