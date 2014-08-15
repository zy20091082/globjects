#pragma once

#include <globjects-base/globjects-base_api.h>
#include <globjects-base/AbstractLogHandler.h>
#include <globjects-base/LogMessage.h>

namespace glo
{

/** \brief Writes LogMessages to stdout.

    This is the default LogMessage handler of globjects.

	\see setLoggingHandler
	\see logging.h
*/
class GLOBJECTS_BASE_API ConsoleLogger : public AbstractLogHandler
{
public:
    virtual void handle(const LogMessage & message) override;

protected:
    static std::string levelString(LogMessage::Level level);
};

} // namespace glo
