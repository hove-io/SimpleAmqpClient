#ifndef SIMPLEPUBLISHER_H
#define SIMPLEPUBLISHER_H

/*
 * ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * ``The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is SimpleAmqpClient for RabbitMQ.
 *
 * The Initial Developer of the Original Code is Alan Antonuk.
 * Original code is Copyright (C) Alan Antonuk.
 *
 * All Rights Reserved.
 *
 * Contributor(s): ______________________________________.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 2 or later (the "GPL"), in
 * which case the provisions of the GPL are applicable instead of those
 * above. If you wish to allow use of your version of this file only
 * under the terms of the GPL, and not to allow others to use your
 * version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the
 * notice and other provisions required by the GPL. If you do not
 * delete the provisions above, a recipient may use your version of
 * this file under the terms of any one of the MPL or the GPL.
 *
 * ***** END LICENSE BLOCK *****
 */

#include "BasicMessage.h"
#include "Channel.h"
#include "Util.h"

#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>

#ifdef _MSC_VER
# pragma warning ( push )
# pragma warning ( disable: 4275 4251 )
#endif

namespace AmqpClient
{

class SIMPLEAMQPCLIENT_EXPORT SimplePublisher : boost::noncopyable
{
public:
	typedef boost::shared_ptr<SimplePublisher> ptr_t;

	friend ptr_t boost::make_shared<SimplePublisher>(AmqpClient::Channel::ptr_t const & a1, std::string const & a2);

	static ptr_t Create(Channel::ptr_t channel, const std::string& publisher_name = "")
	{ return boost::make_shared<SimplePublisher>(channel, publisher_name); }

private:
	explicit SimplePublisher(Channel::ptr_t channel, const std::string& publisher_name);

public:
	virtual ~SimplePublisher();

	std::string getPublisherName() const { return m_publisherExchange; }

	void Publish(const std::string& message);
	void Publish(BasicMessage::ptr_t message);

private:
	Channel::ptr_t m_channel;
	std::string m_publisherExchange;



};

} // namespace AmqpClient

#ifdef _MSC_VER
# pragma warning ( pop )
#endif

#endif // SIMPLEPUBLISHER_H

