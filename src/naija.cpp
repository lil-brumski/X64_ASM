#include <iostream>
#include <thread>
#include <cstring>
#include <cstdlib>

#include <zmq.hpp>
#include <termcolor/termcolor.hpp>

using namespace std::literals;

auto main(void) -> int
{
    auto [ZMQ_MJ, ZMQ_MN, ZMQ_PH] = zmq::version();

    for(size_t cnt = 0; cnt <= 100; cnt+=20){
        std::cout << termcolor::green << "\rStarting Server..." << cnt << "%" << termcolor::reset << std::flush;
        std::this_thread::sleep_for(1000ms);
    }

    std::cout << termcolor::green << "\nCPPZMQ LIBRARY VERSION: " << ZMQ_MJ << "." << ZMQ_MN << "." << ZMQ_PH << "\n"
              << termcolor::reset << std::endl;

    constexpr int kThreads = 2;
    zmq::context_t con( kThreads );

    zmq::socket_t soc( con, zmq::socket_type::rep );
    soc.bind( "tcp://*:5555" );

    while( true )
    {
        zmq::message_t req;
        auto result = soc.recv( req, zmq::recv_flags::none );

        if( result.value_or( 0 ) == 0 )
        {
            std::cerr << "No bytes received!" << std::endl;
            return -1;
        }

        std::cout << termcolor::cyan <<  "Message from client: \"" << req.to_string() << "\"" << termcolor::reset << std::endl;
        std::this_thread::sleep_for(1000ms);

        constexpr std::string_view kReply = "Tamaratare";
        zmq::message_t rep( kReply.length() );
        std::memcpy( rep.data(), kReply.data(), kReply.length() );
        soc.send( rep, zmq::send_flags::none );
    }

    return EXIT_SUCCESS;
}
