#include <iostream>
#include <cstring>

#include <zmq.hpp>
#include <termcolor/termcolor.hpp>

#include <LearnCMake.hpp>


auto main( int argc, char** argv ) -> int {
    zmq::context_t cont( 1 );
    zmq::socket_t soc( cont, zmq::socket_type::req ) ;

    std::cout << "Application written by " << AUTHOR_LEARN_CMAKE << std::endl;
    std::cout << "Version: " << Learn::Version() << std::endl;

    std::cout << termcolor::green << "Connecting to server gang...\n" << termcolor::reset<< std::endl;
    soc.connect("tcp://localhost:5555");

    for( size_t re_ = 1; re_ < 51; re_++ )
    {
        std::string wetin = "Who are you?";
        zmq::message_t request( wetin.length() );
        std::memcpy( request.data(), wetin.data(), wetin.length() );
        std::cout << termcolor::cyan << "[" << re_ <<"] Sending message to server: \"" << wetin << "\"" << termcolor::reset << std::endl;
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