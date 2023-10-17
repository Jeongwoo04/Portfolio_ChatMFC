#include "pch.h"
#include "ServerPacketHandler.h"
#include "ServerSession.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* haeder = reinterpret_cast<PacketHeader*>(buffer);
	return false;
}

bool Handle_S_LOGIN(PacketSessionRef& session, Protocol::S_LOGIN& pkt)
{
	ServerSessionRef serverSession = static_pointer_cast<ServerSession>(session);

	wchar_t convertMsg[1000] = { 0, };
	int len = MultiByteToWideChar(CP_UTF8, 0, pkt.msg().c_str(), pkt.msg().size() + 1, NULL, NULL);
	MultiByteToWideChar(CP_UTF8, 0, pkt.msg().c_str(), pkt.msg().size() + 1, convertMsg, len);

	serverSession->_dig->AddEventString(convertMsg);
	return true;
}

bool Handle_S_CHAT(PacketSessionRef& session, Protocol::S_CHAT& pkt)
{
	ServerSessionRef serverSession = static_pointer_cast<ServerSession>(session);

	wchar_t convertName[100] = { 0, };
	int len = MultiByteToWideChar(CP_UTF8, 0, pkt.name().c_str(), pkt.name().size() + 1, NULL, NULL);
	MultiByteToWideChar(CP_UTF8, 0, pkt.name().c_str(), pkt.name().size() + 1, convertName, len);

	wchar_t convertMsg[1000] = { 0, };
	len = MultiByteToWideChar(CP_UTF8, 0, pkt.msg().c_str(), pkt.msg().size() + 1, NULL, NULL);
	MultiByteToWideChar(CP_UTF8, 0, pkt.msg().c_str(), pkt.msg().size() + 1, convertMsg, len);


	wstring Message = L"[" + static_cast<wstring>(convertName) + L"] : " + convertMsg;

	wstring convertStr = wstring(Message.begin(), Message.end());
	serverSession->_dig->AddEventString(convertStr.c_str());

	return true;
}
