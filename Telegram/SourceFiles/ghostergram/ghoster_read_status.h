/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

class PeerData;
class HistoryItem;
class History;

namespace Main {
class Session;
} // namespace Main

namespace Ui {
class GenericBox;
} // namespace Ui

namespace ghostergram {

enum class GhostReadReceiptsMode : qint32 {
	NewDialogsOnly = 0,
	AllChats = 1,
	Disabled = 2,
};

[[nodiscard]] bool ReadStatusEnabled(not_null<Main::Session*> session);
void SetReadStatusEnabled(not_null<Main::Session*> session, bool enabled);

[[nodiscard]] GhostReadReceiptsMode ReadReceiptsMode(not_null<Main::Session*> session);
void SetReadReceiptsMode(not_null<Main::Session*> session, GhostReadReceiptsMode mode);

[[nodiscard]] bool SendOnlinePackets(not_null<Main::Session*> session);
void SetSendOnlinePackets(not_null<Main::Session*> session, bool send);

[[nodiscard]] bool SendUploadProgress(not_null<Main::Session*> session);
void SetSendUploadProgress(not_null<Main::Session*> session, bool send);

[[nodiscard]] bool SendReadStories(not_null<Main::Session*> session);
void SetSendReadStories(not_null<Main::Session*> session, bool send);

// Starts the per-session watcher, safe to call more than once.
void StartReadStatus(not_null<Main::Session*> session);

// The single gate asked before a read receipt would be sent to the server.
[[nodiscard]] bool ReadStatusHidden(not_null<History*> history);

[[nodiscard]] bool ReadStatusHiddenFor(not_null<PeerData*> peer);

// Stops hiding in this dialog. There is no way back: the receipt is already
// on its way to the server and the other side has already seen the change.
void RevealReadStatus(not_null<PeerData*> peer);

[[nodiscard]] QString ReadStatusTitle();
[[nodiscard]] QString ReadStatusSettingsLabel(
	not_null<Main::Session*> session);

void ReadStatusBox(not_null<Ui::GenericBox*> box, not_null<PeerData*> peer);

} // namespace ghostergram
