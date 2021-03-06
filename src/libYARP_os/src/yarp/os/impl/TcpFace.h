/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_OS_IMPL_TCPFACE_H
#define YARP_OS_IMPL_TCPFACE_H

#include <yarp/conf/system.h>

#include <yarp/os/Face.h>
#include <yarp/os/impl/AuthHMAC.h>
#include <yarp/os/impl/TcpAcceptor.h>

namespace yarp {
namespace os {
namespace impl {

/**
 * Communicating with a port via TCP.
 */
class YARP_os_impl_API TcpFace : public yarp::os::Face
{
public:
    TcpFace();

    ~TcpFace() override;

    bool open(const Contact& address) override;
    void close() override;
    InputProtocol* read() override;
    OutputProtocol* write(const Contact& address) override;

    Contact getLocalAddress() const override;

    /*
     * This class like all classes except the port objects does
     * not have any notion of running in a multi-threaded environment.
     */

protected:
    yarp::os::impl::AuthHMAC auth;

private:
    void closeFace();
    Contact address;
    yarp::os::impl::TcpAcceptor peerAcceptor;
};


} // namespace impl
} // namespace os
} // namespace yarp

#endif // YARP_OS_IMPL_TCPFACE_H
