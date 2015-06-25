#ifndef CHANNELS_RABBIT_RABBITOUTBOUNDCONNECTIONPOINT
#define CHANNELS_RABBIT_RABBITOUTBOUNDCONNECTIONPOINT

#include "../OutBoundConnectionPoint.h"
#include "BaseRabbitConnectionPoint.h"
#include <amqp_tcp_socket.h>
#include <amqp.h>
#include <amqp_framing.h>

namespace HermEsb
{
	namespace Channels
    {
		namespace Rabbit
		{
			/**
			 * Clase que implementa un punto de conexion de salida 
			 * a RabbitMq
			 */
			class HERMESB_API  RabbitOutBoundConnectionPoint : public OutBoundConnectionPoint, public BaseRabbitConnectionPoint
			{
			public:
				/**
                 * Crea una instancia OutBoundConnectionPoint
                 * @param reconnectionTimer Temporizador de reconexion
                 */
                RabbitOutBoundConnectionPoint(char* server, int port, char* exchange, char* routingKey, char* user, char* password, IReconnectionTimer* reconnectionTimer);
                virtual ~RabbitOutBoundConnectionPoint();

			protected:

                /**
                 * Metodo abstracto que establece la conexion fisica con el host
                 * @exception ConnectException Se lanza en el caso que no sea posible la conexion con el host
                 */
                virtual void ConnectPoint() throw (ConnectException);

                /**
                 * Metodo abstracto que cierra la conexion fisica con el host
                 */
                virtual void ClosePoint();

				/**
                 * Envia un mensaje por medio del punto de conexión.
                 * @param message Mensaje a enviar
                 * @param messageLen Longitud del mensaje a enviar
				 * @param priority Prioridad del mensaje a enviar
                 */
                virtual void SendMessage(const void* message,
                        int messageLen, int priority=0);

				char* _exchange;
				char* _routingKey;
				char* _exchangetype;
			};
		}
	}
}

#endif