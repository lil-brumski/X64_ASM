//import x64mod;

#include <iostream>
#include <cstring>

#include <zmq.hpp>
#include <termcolor/termcolor.hpp>
#include <LearnCMake.hpp>
#include "x64_asm.pb.h"

auto main( int argc, char** argv ) -> int {
    //student
    //x64mod::ModState();

    RSU::Student obj1;
    obj1.set_firstname("Tamaratare");
    obj1.set_middlename("Oghenebrume");
    obj1.set_lastname("David");
    obj1.set_isfemale(false);
    obj1.set_department("Computer Engineering");
    obj1.set_phonenumber(12345678900);
    obj1.set_email("67@gmail.com");
    obj1.set_age(19);

    std::cout << obj1.firstname() << " " << obj1.middlename() << " "
              << obj1.lastname() << std::endl;

    ::std::string obj1_data;
    auto const temp = obj1.SerializeToString(&obj1_data);

    zmq::context_t cont( 1 );
    zmq::socket_t soc( cont, zmq::socket_type::req ) ;

    std::cout << "Application written by " << AUTHOR_LEARN_CMAKE << std::endl;
    std::cout << "Version: " << Learn::Version() << std::endl;

    std::cout << termcolor::green << "Connecting to server gang...\n" << termcolor::reset<< std::endl;
    soc.connect("tcp://localhost:5555");

    for( size_t re_ = 1; re_ < 11; re_++ )
    {
        zmq::message_t request( obj1_data.length() );
        std::memcpy( request.data(), obj1_data.data(), obj1_data.length() );
        std::cout << termcolor::cyan << "[" << re_ <<"] Sending message to server: \"" << obj1_data << "\"" << termcolor::reset << std::endl;
        soc.send(request, zmq::send_flags::none);

        zmq::message_t reply;
        auto REPLY = soc.recv(reply, zmq::recv_flags::none);

        if(REPLY.value_or(0) == 0){
            std::cerr << termcolor::red << "Server didn't send shit bro\n" << termcolor::reset << std::endl;
        }
        else{
            std::cout << termcolor::cyan << "Reply from server: \"" << reply.to_string() << "\"\n" << termcolor::reset << std::endl;
        }
    }

    return 0;
}