//
//  main.cpp
//  BACppFileMonitor
//
//  Created by Salvador Guerrero on 3/8/16.
//  Copyright © 2016 ByteApps. All rights reserved.
//

#include <boost/lambda/lambda.hpp>
#include <boost/filesystem.hpp>

#include <iostream>
#include <iterator>
#include <algorithm>

void filesystem_test(int argc, const char * argv[])
{
    using namespace boost::filesystem;

//    if (argc < 2)
//    {
//        std::cout << "Usage: tut1 path\n";
//        exit(1);
//    }

    std::cout << argv[0] << " " << file_size(argv[0]) << '\n';
}

void lambda_test()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " " );
}

int main(int argc, const char * argv[])
{
    filesystem_test(argc, argv);
    lambda_test();

    return 0;
}
