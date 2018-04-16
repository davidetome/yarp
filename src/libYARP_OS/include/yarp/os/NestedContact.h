/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_OS_NESTEDCONTACT_H
#define YARP_OS_NESTEDCONTACT_H

#include <yarp/os/api.h>
#include <yarp/os/ConstString.h>

namespace yarp {
namespace os {

/**
 *
 * A placeholder for rich contact information.  Includes types, and
 * can express a ROS-style node/topic or node/service combination.
 *
 */
class YARP_OS_API NestedContact
{
public:
    /** @{ */

    /**
     * @brief Default constructor.
     */
    NestedContact();

    /**
     * @brief Constructor.
     *
     * @param fullName the full name.
     */
    NestedContact(const ConstString& fullName);

    /**
     * @brief Copy constructor.
     *
     * @param rhs the NestedContact to copy
     */
    NestedContact(const NestedContact& rhs);

    /**
     * @brief Move constructor.
     *
     * @param rhs the NestedContact to be moved
     */
    NestedContact(NestedContact&& rhs);

    /**
     * @brief Destructor.
     */
    ~NestedContact();

    /**
     * Copy assignment operator.
     *
     * @param rhs the NestedContact to copy
     * @return this object
     */
    NestedContact& operator=(const NestedContact& rhs);

    /**
     * @brief Move assignment operator.
     *
     * @param rhs the NestedContact to be moved
     * @return this object
     */
    NestedContact& operator=(NestedContact&& rhs);

    /** @} */
    /** @{ */

    bool fromString(const ConstString& nFullName);

    void setTypeName(const ConstString& nWireType);

    void setCategoryWrite();

    void setCategoryRead();

    ConstString getFullName() const;

    ConstString getNodeName() const;

    ConstString getNestedName() const;

    ConstString getCategory() const;

    ConstString getTypeName() const;

    ConstString getTypeNameStar() const;

    bool isNested() const;

    ConstString toString() const;

    /** @} */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:
    class Private;
    Private* mPriv;
#endif // DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace os
} // namespace yarp

#endif // YARP_OS_NESTEDCONTACT_H
