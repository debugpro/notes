#ifndef STRUCTS_H
#define STRUCTS_H

#include "typedefs.h"
#include "enums.h"
#include "windows.h"

/// ActionFrame specifies the frame of each animation for which an action is
/// triggered.
///
/// size = 0xB
typedef struct {
	/// offset: 0000 (1 bytes)
	int8_t dungeon_stand_frame;
	/// offset: 0001 (1 bytes)
	int8_t attack_frame;
	/// offset: 0002 (1 bytes)
	int8_t dungeon_walk_frame;
	/// offset: 0003 (1 bytes)
	int8_t block_frame;
	/// offset: 0004 (1 bytes)
	int8_t death_frame;
	/// offset: 0005 (1 bytes)
	int8_t spell_frame;
	/// offset: 0006 (1 bytes)
	int8_t hit_frame;
	/// offset: 0007 (1 bytes)
	int8_t town_stand_frame;
	/// offset: 0008 (1 bytes)
	int8_t town_walk_frame;
	/// offset: 0009 (1 bytes)
	int8_t attack_frame_unknown_0009;
	/// offset: 000A (1 bytes)
	int8_t attack_frame_unknown_000A;
} ActionFrame;

/// A BlockEntry is an MPQ block table entry.
///
/// size = 0x10
typedef struct {
	/// offset: 0000 (4 bytes)
	/// Offset to the start of the block.
	uint32_t block_offset;
	/// offset: 0004 (4 bytes)
	/// Size in bytes of the block.
	uint32_t block_size;
	/// offset: 0008 (4 bytes)
	/// Size in bytes of the uncompressed file.
	uint32_t file_size;
	/// offset: 000C (4 bytes)
	/// Flags associated with the block.
	block_flag flags;
} BlockEntry;

/// Caps specifies the network message capabilities of the client.
///
/// size = 0x24
typedef struct {
	/// offset: 00000000 (4 bytes)
	int size;
	/// offset: 00000008 (4 bytes)
	int max_msg_size;
	/// offset: 00000010 (4 bytes)
	int max_players;
	/// offset: 00000014 (4 bytes)
	int unknown_0014;
	/// offset: 0000001C (4 bytes)
	int unknown_001C;
	/// offset: 00000020 (4 bytes)
	int nturns_in_transit;
} Caps;

/// Cmd is a command message without body.
///
/// PSX def:
///     typedef struct TCmd {
///        unsigned char bCmd;
///     } TCmd;
///
/// size = 0x1
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
} Cmd;

/// CmdCoord is a command message with X-Y coordinate.
///
/// PSX def:
///     typedef struct TCmdLoc {
///        unsigned char bCmd;
///        unsigned char x;
///        unsigned char y;
///     } TCmdLoc;
///
/// size = 0x3
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t x;
	/// offset: 0002 (1 bytes)
	int8_t y;
} CmdCoord;

/// CmdCoordParam1 is a command message with X-Y coordinate and one parameter.
///
/// PSX def:
///     typedef struct TCmdLocParam1 {
///        unsigned char bCmd;
///        unsigned char x;
///        unsigned char y;
///        unsigned short wParam1;
///     } TCmdLocParam1;
///
/// size = 0x5
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t x;
	/// offset: 0002 (1 bytes)
	int8_t y;
	/// offset: 0003 (2 bytes)
	int16_t param1;
} CmdCoordParam1;

/// CmdCoordParam2 is a command message with X-Y coordinate and two parameters.
///
/// PSX def:
///     typedef struct TCmdLocParam2 {
///        unsigned char bCmd;
///        unsigned char x;
///        unsigned char y;
///        unsigned short wParam1;
///        unsigned short wParam2;
///     } TCmdLocParam2;
///
/// size = 0x7
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t x;
	/// offset: 0002 (1 bytes)
	int8_t y;
	/// offset: 0003 (2 bytes)
	int16_t param1;
	/// offset: 0005 (2 bytes)
	int16_t param2;
} CmdCoordParam2;

/// CmdCoordParam3 is a command message with X-Y coordinate and three parameters.
///
/// PSX def:
///     typedef struct TCmdLocParam3 {
///        unsigned char bCmd;
///        unsigned char x;
///        unsigned char y;
///        unsigned short wParam1;
///        unsigned short wParam2;
///        unsigned short wParam3;
///     } TCmdLocParam3;
///
/// size = 0x9
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t x;
	/// offset: 0002 (1 bytes)
	int8_t y;
	/// offset: 0003 (2 bytes)
	int16_t param1;
	/// offset: 0005 (2 bytes)
	int16_t param2;
	/// offset: 0007 (2 bytes)
	int16_t param3;
} CmdCoordParam3;

/// CmdParam1 is a command message with one parameter.
///
/// PSX def:
///     typedef struct TCmdParam1 {
///        unsigned char bCmd;
///        unsigned short wParam1;
///     } TCmdParam1;
///
/// size = 0x3
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (2 bytes)
	int16_t param1;
} CmdParam1;

/// CmdParam2 is a command message with two parameters.
///
/// PSX def:
///     typedef struct TCmdParam2 {
///        unsigned char bCmd;
///        unsigned short wParam1;
///        unsigned short wParam2;
///     } TCmdParam2;
///
/// size = 0x5
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (2 bytes)
	int16_t param1;
	/// offset: 0003 (2 bytes)
	int16_t param2;
} CmdParam2;

/// CmdParam3 is a command message with three parameters.
///
/// PSX def:
///     typedef struct TCmdParam3 {
///        unsigned char bCmd;
///        unsigned short wParam1;
///        unsigned short wParam2;
///        unsigned short wParam3;
///     } TCmdParam3;
///
/// size = 0x7
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (2 bytes)
	int16_t param1;
	/// offset: 0003 (2 bytes)
	int16_t param2;
	/// offset: 0005 (2 bytes)
	int16_t param3;
} CmdParam3;

/// CmdSpawnGolem is a SpawnGolem command message.
///
/// PSX def:
///     typedef struct TCmdGolem {
///        unsigned char bCmd;
///        unsigned char _mx;
///        unsigned char _my;
///        unsigned char _mdir;
///        unsigned char _menemy;
///        unsigned char _currlevel;
///        short _mhitpoints;
///     } TCmdGolem;
///
/// size = 0xA
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t x;
	/// offset: 0002 (1 bytes)
	int8_t y;
	/// offset: 0003 (1 bytes)
	direction direction;
	/// offset: 0004 (1 bytes)
	int8_t target_num;
	/// offset: 0005 (4 bytes)
	int32_t hp;
	/// offset: 0009 (1 bytes)
	int8_t dlvl;
} CmdSpawnGolem;

/// CmdQuest is a Quest command message.
///
/// PSX def:
///     typedef struct TCmdQuest {
///        unsigned char bCmd;
///        unsigned char q;
///        unsigned char qstate;
///        unsigned char qlog;
///        unsigned char qvar1;
///     } TCmdQuest;
///
/// size = 0x5
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	quest_id quest_id;
	/// offset: 0002 (1 bytes)
	bool8_t quest_active;
	/// offset: 0003 (1 bytes)
	bool8_t speech_spoken;
	/// offset: 0004 (1 bytes)
	int8_t var1;
} CmdQuest;

/// CmdGetItem is a GetItem command message.
///
/// PSX def:
///     typedef struct TCmdGItem {
///        unsigned char bCmd;
///        unsigned char bMaster;
///        unsigned char bPnum;
///        unsigned char bCursitem;
///        unsigned char bLevel;
///        unsigned char x;
///        unsigned char y;
///        unsigned char bId;
///        unsigned char bDur;
///        unsigned char bMDur;
///        unsigned char bCh;
///        unsigned char bMCh;
///        unsigned short wValue;
///        unsigned short wIndx;
///        unsigned short wCI;
///        unsigned long dwSeed;
///        unsigned long dwBuff;
///        unsigned long dwTime;
///     } TCmdGItem;
///
/// size = 0x1E
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t player_num_master;
	/// offset: 0002 (1 bytes)
	int8_t player_num;
	/// offset: 0003 (1 bytes)
	int8_t item_num;
	/// offset: 0004 (1 bytes)
	int8_t dlvl;
	/// offset: 0005 (1 bytes)
	int8_t x;
	/// offset: 0006 (1 bytes)
	int8_t y;
	/// offset: 0007 (2 bytes)
	int16_t item_id;
	/// offset: 0009 (2 bytes)
	int16_t wCF;
	/// offset: 000B (4 bytes)
	int32_t seed;
	/// offset: 000F (1 bytes)
	int8_t identified;
	/// offset: 0010 (1 bytes)
	int8_t durability_cur;
	/// offset: 0011 (1 bytes)
	int8_t durability_max;
	/// offset: 0012 (1 bytes)
	int8_t charges_cur;
	/// offset: 0013 (1 bytes)
	int8_t charges_max;
	/// offset: 0014 (2 bytes)
	int16_t gold_price_min;
	/// offset: 001A (4 bytes)
	int32_t tc;
} CmdGetItem;

/// CmdPutItem is a PutItem command message.
///
/// PSX def:
///     typedef struct TCmdPItem {
///        unsigned char bCmd;
///        unsigned char x;
///        unsigned char y;
///        unsigned char bId;
///        unsigned char bDur;
///        unsigned char bMDur;
///        unsigned char bCh;
///        unsigned char bMCh;
///        unsigned short wValue;
///        unsigned short wIndx;
///        unsigned short wCI;
///        unsigned long dwSeed;
///        unsigned long dwBuff;
///     } TCmdPItem;
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t x;
	/// offset: 0002 (1 bytes)
	int8_t y;
	/// offset: 0003 (2 bytes)
	int16_t item_id;
	/// offset: 0005 (2 bytes)
	uint16_t wCF;
	/// offset: 0007 (4 bytes)
	int32_t seed;
	/// offset: 000B (1 bytes)
	bool8_t identified;
	/// offset: 000C (1 bytes)
	int8_t durability_cur;
	/// offset: 000D (1 bytes)
	int8_t durability_max;
	/// offset: 000E (1 bytes)
	int8_t charges_cur;
	/// offset: 000F (1 bytes)
	int8_t charges_max;
	/// offset: 0010 (2 bytes)
	int16_t gold_price;
	/// offset: 0012 (4 bytes)
	/// only used by ear to store name of character.
	uint32_t only_used_by_ear;
} CmdPutItem;

/// PSX def:
///     typedef struct TCmdChItem {
///        unsigned char bCmd;
///        unsigned char bLoc;
///        unsigned short wIndx;
///        unsigned short wCI;
///        unsigned long dwSeed;
///        unsigned char bId;
///     } TCmdChItem;
///
/// size = 0xB
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t item_body_num;
	/// offset: 0002 (2 bytes)
	item_id item_id;
	/// offset: 0004 (2 bytes)
	int16_t wCF;
	/// offset: 0006 (4 bytes)
	int32_t seed;
	/// offset: 000A (1 bytes)
	bool8_t identified;
} CmdChangeItem;

/// PSX def:
///     typedef struct TCmdDelItem {
///        unsigned char bCmd;
///        unsigned char bLoc;
///     } TCmdDelItem;
///
/// size = 0x2
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
	/// offset: 0001 (1 bytes)
	int8_t item_body_num;
} CmdDeleteItem;

/// ClientInfo specifies information about the game version of the client.
///
/// size = 0x3C
typedef struct {
	/// offset: 0000 (4 bytes)
	/// size of ClientInfo struct.
	int size;
	/// offset: 0004 (4 bytes)
	char *release_name;
	/// offset: 0008 (4 bytes)
	char *version;
	/// offset: 000C (4 bytes)
	/// 'DRTL' (Diablo Retail)
	uint32_t release_id;
	/// offset: 0010 (4 bytes)
	int unknown_0010;
	/// offset: 0018 (4 bytes)
	int unknown_0018;
	/// offset: 001C (4 bytes)
	int32_t multi_seed;
	/// offset: 0020 (4 bytes)
	int unknown_0020;
	/// offset: 0028 (4 bytes)
	int unknown_0028;
	/// offset: 0038 (4 bytes)
	uint32_t languageID;
} ClientInfo;

/// Coord specifies an X-Y coordinate of the map.
typedef struct {
	int8_t x;
	int8_t y;
} Coord;

/// CircleCoords specifies X- and Y-coordinate deltas from the center of a
/// circle.
///
/// n=4
///
///     1
///    3#4
///     2
///
/// n=16
///
///     314
///    B7 8C
///    F # G
///    D9 AE
///     526
///
/// size = 0xABD
typedef struct {
	/// offset: 0000 (1 bytes)
	int8_t n_1;
	/// offset: 0001 (2 bytes)
	Coord delta_1[1];
	/// offset: 0003 (1 bytes)
	int8_t n_4;
	/// offset: 0004 (8 bytes)
	Coord delta_4[4];
	/// offset: 000C (1 bytes)
	int8_t n_16;
	/// offset: 000D (32 bytes)
	Coord delta_16[16];
	/// offset: 002D (1 bytes)
	int8_t n_24;
	/// offset: 002E (48 bytes)
	Coord delta_24[24];
	/// offset: 005E (1 bytes)
	int8_t n_32;
	/// offset: 005F (64 bytes)
	Coord delta_32[32];
	/// offset: 009F (1 bytes)
	int8_t n_40;
	/// offset: 00A0 (80 bytes)
	Coord delta_40[40];
	/// offset: 00F0 (1 bytes)
	int8_t n_48;
	/// offset: 00F1 (96 bytes)
	Coord delta_48[48];
	/// offset: 0151 (1 bytes)
	int8_t n_56;
	/// offset: 0152 (112 bytes)
	Coord delta_56[56];
	/// offset: 01C2 (1 bytes)
	int8_t n_64;
	/// offset: 01C3 (128 bytes)
	Coord delta_64[64];
	/// offset: 0243 (1 bytes)
	int8_t n_72;
	/// offset: 0244 (144 bytes)
	Coord delta_72[72];
	/// offset: 02D4 (1 bytes)
	int8_t n_80;
	/// offset: 02D5 (160 bytes)
	Coord delta_80[80];
	/// offset: 0375 (1 bytes)
	int8_t n_88;
	/// offset: 0376 (176 bytes)
	Coord delta_88[88];
	/// offset: 0426 (1 bytes)
	int8_t n_96;
	/// offset: 0427 (192 bytes)
	Coord delta_96[96];
	/// offset: 04E7 (1 bytes)
	int8_t n_104;
	/// offset: 04E8 (208 bytes)
	Coord delta_104[104];
	/// offset: 05B8 (1 bytes)
	int8_t n_112;
	/// offset: 05B9 (224 bytes)
	Coord delta_112[112];
	/// offset: 0699 (1 bytes)
	int8_t n_120;
	/// offset: 069A (240 bytes)
	Coord delta_120[120];
	/// offset: 078A (1 bytes)
	int8_t n_128;
	/// offset: 078B (256 bytes)
	Coord delta_128[128];
	/// offset: 088B (1 bytes)
	int8_t n_136;
	/// offset: 088C (272 bytes)
	Coord delta_136[136];
	/// offset: 099C (1 bytes)
	int8_t n_144;
	/// offset: 099D (288 bytes)
	Coord delta_144[144];
} CircleCoords;

/// DeltaObject contains delta information about an object to be synchronized
/// with connected peers.
///
/// PSX def:
///    typedef struct DObjectStr {
///       unsigned char bCmd;
///    } DObjectStr;
typedef struct {
	/// offset: 0000 (1 bytes)
	cmd cmd;
} DeltaObject;

/// DeltaMonster contains delta information about a monster to be synchronized
/// with connected peers.
///
/// PSX def:
///    typedef struct DMonsterStr {
///       unsigned char _mx;
///       unsigned char _my;
///       unsigned char _mdir;
///       unsigned char _menemy;
///       int _mhitpoints;
///    } DMonsterStr;
typedef struct {
	/// offset: 0000 (1 bytes)
	int8_t x;
	/// offset: 0001 (1 bytes)
	int8_t y;
	/// offset: 0002 (1 bytes)
	/// TODO: document field name.
	int8_t field_0002;
	/// offset: 0003 (1 bytes)
	int8_t target_num;
	/// offset: 0004 (1 bytes)
	///
	/// Activity threshold (squelch).
	///    activity_threshold == 0   // Inactive.
	///    activity_threshold > 0    // Active, can perform most actions.
	///    activity_threshold == 255 // Active, can perform all actions.
	///
	/// At each monster update (20 times per sec) the activity threshold is set to
	/// 255 if the monster is within line of sight from the player. If the monster
	/// is outside of line of sight, the threshold is decremented by 1 until it
	/// reaches 0.
	///
	///    activity_threshold -= 1  // Decrement when player is outside of line of sight.
	///    activity_threshold = 255 // Set when player is within line of sight.
	int8_t activity_threshold;
	/// offset: 0005 (4 bytes)
	int32_t hp;
} DeltaMonster;

/// DeltaLevel contains delta information about items, objects and monsters of a
/// dungeon level to be synchronized with connected peers.
///
/// size = 0x1271
typedef struct {
	/// offset: 0000 (2794 bytes)
	CmdPutItem items[127];
	/// offset: 0AEA (127 bytes)
	DeltaObject objects[127];
	/// offset: 0B69 (1800 bytes)
	DeltaMonster monsters[200];
} DeltaLevel;

/// 10 blocks for l1.min, l2.min and l3.min
/// 16 blocks for l4.min and town.min
const int nblocks = 10;

/// A DPiece represents a dungeon piece, which specifies how to arrange frames of
/// a level CEL file in order to form a miniature tile. A dungeon piece consists
/// of 10 or 16 blocks, where each non-empty block is represented by a CEL frame.
///
/// A block specifies the graphics of a single block in a dungeon piece.
///
/// Frame number in the level CEL file; or 0 if empty;
///    block&0x0FFF.
///
/// Frame type, specifying the CEL decoding algorithm of the frame;
///    (block&0x7000) >> 12
typedef struct {
	/// Either 10 or 16 blocks constituting the dungeon piece.
	uint16_t blocks[nblocks];
} DPiece;

/// Event is a network game player event.
///
/// size = 0x10
typedef struct {
	/// offset: 0000 (4 bytes)
	event_type event_type;
	/// offset: 0004 (4 bytes)
	int player_num;
	/// offset: 0008 (4 bytes)
	void *data;
	/// offset: 000C (4 bytes)
	int len;
} Event;

/// FileInfo provides information about the game executable and asset archives.
typedef struct {
	/// offset: 0000 (4 bytes)
	int32_t size;
	/// offset: 0004 (4 bytes)
	char *version;
	/// offset: 0008 (4 bytes)
	char *diablo_exe_path;
	/// offset: 000C (4 bytes)
	char *diabdat_mpq_path;
	/// offset: 0010 (4 bytes)
	char *patch_mpq_path;
} FileInfo;

/// GossipData specifies the speech IDs for the gossip related to each quest.
typedef struct {
	/// offset 0000 (4 bytes)
	speech_id the_magic_rock;
	/// offset 0004 (4 bytes)
	speech_id black_mushroom;
	/// offset 0008 (4 bytes)
	speech_id gharbad_the_weak;
	/// offset 000C (4 bytes)
	speech_id zhar_the_mad;
	/// offset 0010 (4 bytes)
	speech_id lachdanan;
	/// offset 0014 (4 bytes)
	speech_id diablo;
	/// offset 0018 (4 bytes)
	speech_id the_butcher;
	/// offset 001C (4 bytes)
	speech_id ogdens_sign;
	/// offset 0020 (4 bytes)
	speech_id halls_of_the_blind;
	/// offset 0024 (4 bytes)
	speech_id valor;
	/// offset 0028 (4 bytes)
	speech_id anvil_of_fury;
	/// offset 002C (4 bytes)
	speech_id warlord_of_blood;
	/// offset 0030 (4 bytes)
	speech_id the_curse_of_king_leoric;
	/// offset 0034 (4 bytes)
	speech_id poisoned_water_supply;
	/// offset 0038 (4 bytes)
	speech_id the_chamber_of_bone;
	/// offset 003C (4 bytes)
	speech_id archbishop_lazarus;
} GossipData;

/// A HashEntry is an MPQ hash table entry.
///
/// size = 0x10
typedef struct {
	/// offset: 0000 (4 bytes)
	/// Hash of relative file path, using method A.
	uint32_t hash_a;
	/// offset: 0004 (4 bytes)
	/// Hash of relative file path, using method B.
	uint32_t hash_b;
	/// offset: 0008 (2 bytes)
	/// Language locale of the file.
	uint16_t locale;
	/// offset: 000A (2 bytes)
	/// Platform of the file.
	uint16_t platform;
	/// offset: 000C (4 bytes)
	/// Index into the block table for the file; or one of the following two values.
	uint32_t block_index;
} HashEntry;

/// HeroItem contains the most essential information about the item of a player,
/// as used in save files.
///
/// size = 0x13
typedef struct {
	/// offset 0000 (4 bytes)
	int32_t seed;
	/// offset 0004 (2 bytes)
	uint16_t wCF;
	/// offset 0006 (2 bytes)
	item_id item_id;
	/// offset 0008 (1 byte)
	/// The first bit corresponds to identified and the remaining bits corresponds to item_quality.
	uint8_t identified_and_item_quality;
	/// offset 0009 (1 byte)
	int8_t durability_cur;
	/// offset 000A (1 byte)
	int8_t durability_max;
	/// offset 000B (1 byte)
	int8_t charges_min;
	/// offset 000C (1 byte)
	int8_t charges_max;
	/// offset 000D (2 bytes)
	int16_t gold_price;
	/// offset 000F (4 bytes)
	/// Stores the last 4 bytes of the ear name.
	uint32_t only_used_by_ear;
} HeroItem;

/// Hero contains the most essential information about a player, as used in save
/// files.
///
/// size = 0x4F2
typedef struct {
	/// offset 0008 (1 bytes)
	int8_t daction;
	/// offset 0009 (1 bytes)
	int8_t param1;
	/// offset 000A (1 bytes)
	int8_t param2;
	/// offset 000B (1 bytes)
	int8_t dlvl;
	/// offset 000C (1 bytes)
	int8_t x;
	/// offset 000D (1 bytes)
	int8_t y;
	/// offset 000E (1 bytes)
	int8_t target_x;
	/// offset 000F (1 bytes)
	int8_t target_y;
	/// offset 0010 (32 bytes)
	char name[32];
	/// offset 0030 (1 bytes)
	player_class player_class;
	/// offset 0031 (1 bytes)
	int8_t str_base;
	/// offset 0032 (1 bytes)
	int8_t mag_base;
	/// offset 0033 (1 bytes)
	int8_t dex_base;
	/// offset 0034 (1 bytes)
	int8_t vit_base;
	/// offset 0035 (1 bytes)
	int8_t clvl;
	/// offset 0036 (1 bytes)
	int8_t points;
	/// offset 0037 (4 bytes)
	int32_t exp;
	/// offset 003B (4 bytes)
	int32_t gold_total;
	/// offset 003F (4 bytes)
	int32_t hp_base_cur;
	/// offset 0043 (4 bytes)
	int32_t hp_base_max;
	/// offset 0047 (4 bytes)
	int32_t mp_base_cur;
	/// offset 004B (4 bytes)
	int32_t mp_base_max;
	/// offset 004F (37 bytes)
	int8_t spell_lvl_from_spell_id[37];
	/// offset 0074 (8 bytes)
	/// bitfield of known spells.
	uint32_t known_spells[2];
	/// offset 007C (133 bytes)
	HeroItem body_items[7];
	/// offset 0101 (760 bytes)
	HeroItem inv_items[40];
	/// offset 03F9 (40 bytes)
	int8_t inv_num_from_inv_grid[40];
	/// offset 0421 (1 bytes)
	int8_t ninv_items;
	/// offset 0422 (152 bytes)
	HeroItem belt_items[8];
	/// offset 04BD (1 bytes)
	int8_t on_battlenet;
	/// offset 04BE (1 bytes)
	int8_t has_manashild;
	/// offset 04D2 (4 bytes)
	int32_t difficulty;
} Hero;

/// HeroInfo specifies information about the hero to be presented in the user
/// interface.
///
/// PSX def:
///    typedef struct _uiheroinfo {
///       struct _uiheroinfo* next;
///       char name[16];
///       unsigned short level;
///       unsigned char heroclass;
///       unsigned char herorank;
///       unsigned short strength;
///       unsigned short magic;
///       unsigned short dexterity;
///       unsigned short vitality;
///       unsigned long gold;
///       unsigned char hassaved;
///       unsigned char spawned;
///    } TUIHEROINFO, _uiheroinfo;
///
/// size = 0x2C
typedef struct HeroInfo {
	/// offset: 0000 (4 bytes)
	struct HeroInfo *next;
	/// offset: 0004 (16 bytes)
	char name[16];
	/// offset: 0014 (2 bytes)
	int16_t clvl;
	/// offset: 0016 (1 bytes)
	player_class player_class;
	/// offset: 0017 (1 bytes)
	/// TODO: use difficulty enum
	int8_t difficulty;
	/// offset: 0018 (2 bytes)
	int16_t str_cur;
	/// offset: 001A (2 bytes)
	int16_t mag_cur;
	/// offset: 001C (2 bytes)
	int16_t dex_cur;
	/// offset: 001E (2 bytes)
	int16_t vit_cur;
	/// offset: 0020 (4 bytes)
	int32_t gold_total;
	/// offset: 0024 (4 bytes)
	bool32_t has_save;
	/// offset: 0028 (4 bytes)
	bool32_t spawned;
} HeroInfo;

/// Item describes in-game state of any game item.
///
/// size = 0x170
typedef struct {
	/// offset 0000 (4 bytes)
	uint32_t seed;
	/// offset 0004 (2 bytes)
	uint16_t CF;
	/// offset 0008 (4 bytes)
	item_type type;
	/// offset 000C (4 bytes)
	int32_t x;
	/// offset 0010 (4 bytes)
	int32_t y;
	/// offset 0014 (4 bytes)
	int32_t drop_anim_update;
	/// offset 0018 (4 bytes)
	void *drop_cel_data;
	/// offset 001C (4 bytes)
	int32_t drop_frame_count;
	/// offset 0020 (4 bytes)
	int32_t cur_drop_frame;
	/// offset 0024 (4 bytes)
	int32_t drop_width;
	/// offset 0028 (4 bytes)
	int32_t drop_x_offset;
	/// offset 002C (4 bytes)
	/// unused in win 1.09b, used in win 1.00 debug.
	bool32_t inactive;
	/// offset 0030 (1 byte)
	item_drop_state drop_state;
	/// offset 0034 (4 bytes)
	bool32_t draw_quest_item;
	/// offset 0038 (4 bytes)
	bool32_t is_identified;
	/// offset 003C (1 byte)
	item_quality quality;
	/// offset 003D (64 bytes)
	char unindentified_name[64];
	/// offset 007D (64 bytes)
	char full_name[64];
	/// offset 00BD (1 byte)
	item_equip_type equip_type;
	/// offset 00BE (1 byte)
	item_class _class;
	/// offset 00C0 (4 bytes)
	item_inv_graphics_id inv_graphics_id;
	/// offset 00C4 (4 bytes)
	/// also represents number of gold pieces for item `gold`
	int32_t unindentified_price;
	/// offset 00C8 (4 bytes)
	int32_t full_price;
	/// offset 00CC (4 bytes)
	int32_t min_attack_damage;
	/// offset 00D0 (4 bytes)
	int32_t max_attack_damage;
	/// offset 00D4 (4 bytes)
	int32_t armor_class;
	/// offset 00D8 (4 bytes)
	/// bitmask
	item_special_effect special_effect_flags;
	/// offset 00DC (4 bytes)
	item_misc_id misc_id;
	/// offset 00E0 (4 bytes)
	spell_id item_spell_id;
	/// offset 00E4 (4 bytes)
	int32_t cur_staff_charges;
	/// offset 00E8 (4 bytes)
	int32_t max_staff_charges;
	/// offset 00EC (4 bytes)
	int32_t cur_durability;
	/// offset 00F0 (4 bytes)
	/// if it equals 255 then item is indestructible
	int32_t max_durability;
	/// offset 00F4 (4 bytes)
	int32_t attack_damage_percent_bonus;
	/// offset 00F8 (4 bytes)
	int32_t to_hit_bonus;
	/// offset 00FC (4 bytes)
	int32_t armor_class_percent_bonus;
	/// offset 0100 (4 bytes)
	int32_t strength_bonus;
	/// offset 0104 (4 bytes)
	int32_t magic_bonus;
	/// offset 0108 (4 bytes)
	int32_t dexterity_bonus;
	/// offset 010C (4 bytes)
	int32_t vitality_bonus;
	/// offset 0110 (4 bytes)
	int32_t fire_resistance_bonus;
	/// offset 0114 (4 bytes)
	int32_t lightning_resistance_bonus;
	/// offset 0118 (4 bytes)
	int32_t magic_resistance_bonus;
	/// offset 011C (4 bytes)
	/// in Q26.6 fixed-point format (each displayed mana point equals 64)
	int32_t mana_bonus;
	/// offset 0120 (4 bytes)
	/// in Q26.6 fixed-point format (each displayed health point equals 64)
	int32_t life_bonus;
	/// offset 0124 (4 bytes)
	int32_t attack_damage_bonus;
	/// offset 0128 (4 bytes)
	int32_t damage_taken_bonus;
	/// offset 012C (4 bytes)
	/// measured in 10% chunks
	int32_t light_radius_bonus;
	/// offset 0130 (1 byte)
	uint8_t spell_level_bonus;
	/// offset 0131 (1 byte)
	bool8_t held_in_hand;
	/// offset 0134 (4 bytes)
	unique_item_id unique_id;
	/// offset 0138 (4 bytes)
	int32_t fire_damage_min;
	/// offset 013C (4 bytes)
	int32_t fire_damage_max;
	/// offset 0140 (4 bytes)
	int32_t lightning_damage_min;
	/// offset 0144 (4 bytes)
	int32_t lightning_damage_max;
	/// offset 0148 (4 bytes)
	int32_t armor_penetration;
	/// offset 014C (4 bytes)
	item_effect_type prefix_effect_type;
	/// offset 014D (4 bytes)
	item_effect_type suffix_effect_type;
	/// offset 0150 (4 bytes)
	int32_t prefix_price;
	/// offset 0154 (4 bytes)
	int32_t prefix_price_multiplier;
	/// offset 0158 (4 bytes)
	int32_t suffix_price;
	/// offset 015C (4 bytes)
	int32_t suffix_price_multiplier;
	/// offset 0160 (1 byte)
	uint8_t required_strength;
	/// offset 0161 (1 byte)
	uint8_t reguied_magic;
	/// offset 0162 (1 byte)
	uint8_t required_dexterity;
	/// offset 0163 (1 byte)
	uint8_t required_vitality;
	/// offset 0164 (4 bytes)
	bool32_t is_equippable;
	/// offset 0168 (4 bytes)
	item_id id;
} Item;

/// ItemData describes possible basic state a of game item (i.e. state before possibly applying
/// prefix, suffix, unique, effects or spells for books or staves)
///
/// size = 0x4C
typedef struct {
	/// offset 0000 (4 bytes)
	item_drop_rate drop_rate;
	/// offset 0004 (1 byte)
	item_class _class;
	/// offset 0005 (1 byte)
	item_equip_type equip_type;
	/// offset 0008 (4 bytes)
	item_inv_graphics_id inv_graphics_id;
	/// offset 000C (1 byte)
	item_type type;
	/// offset 000D (1 byte)
	unique_base_item unique_base_item_id;
	/// offset 0010 (4 bytes)
	const char *name;
	/// offset 0014 (4 bytes)
	/// applied if item description becomes too long after adding affixes
	/// and/or spell
	const char *short_name;
	/// offset 0018 (4 bytes)
	item_quality quality;
	/// offset 001C (4 bytes)
	int max_durability;
	/// offset 0020 (4 bytes)
	int min_attack_damage;
	/// offset 0024 (4 bytes)
	int max_attack_damage;
	/// offset 0028 (4 bytes)
	int min_armor_class;
	/// offset 002C (4 bytes)
	int max_armor_class;
	/// offset 0030 (1 byte)
	uint8_t required_strength;
	/// offset 0031 (1 byte)
	uint8_t required_magic;
	/// offset 0032 (1 byte)
	uint8_t required_dexterity;
	/// offset 0034 (4 bytes)
	/// Rarely set, only for undead crown and even this
	/// case seems to be redundant due one of its unique
	/// item effect
	item_special_effect special_effect_flags;
	/// offset 0038 (4 bytes)
	item_misc_id misc_id;
	/// offset 003C (4 bytes)
	/// Used for charges on Short Staff of Charged Bolt,
	/// and used for scrolls otherwise.
	spell_id spell_id;
	/// offset 0040 (4 bytes)
	/// Set if item could be triggered with right click (e.g. for gold,
	/// potions, elixirs, books and scrolls). Some unique items do still
	/// trigger an action on right click even though for them this flag
	/// is not set.
	bool32_t is_usable;
	/// offset 0044 (4 bytes)
	int price;
	/// offset 0048 (4 bytes)
	/// Unused but for all items is specified higher than price
	int max_price;
} ItemData;

/// ItemEffect describes possible effect caused by suffix or prefix of magic item or one of
/// 5 unique item's effects. For some rare effect types min/max values represent different
/// type of parameters.
typedef struct {
	item_effect_type type;
	int32_t min_value;
	int32_t max_value;
} ItemEffect;

/// ItemAffixData describes effect and properties of affix with listed name.
///
/// PSX def:
///    typedef struct PLStruct {
///       int PLName;
///       int PLPower;
///       int PLParam1;
///       int PLParam2;
///       char PLMinLvl;
///       long PLIType;
///       unsigned char PLGOE;
///       unsigned char PLDouble;
///       unsigned char PLOk;
///       int PLMinVal;
///       int PLMaxVal;
///       int PLMultVal;
///    } PLStruct;
///
/// size = 0x30
typedef struct {
	/// offset 0000 (4 bytes)
	const char *name;
	/// offset 0004 (12 bytes)
	ItemEffect effect;
	/// offset 0010 (1 bytes)
	int8_t quality_level;
	/// offset 0014 (4 bytes)
	/// bitmask
	affix_item_type item_type_flags;
	/// offset 0018 (4 bytes)
	/// contains 0x01 or 0x10. If (suffix | preffix) == 0x11 they will
	/// never be applied to a single item simultaneously. Also if prefix
	/// has value 0x01 it also means that it can not be present on a staff
	/// with a spell.
	int excluded_combination;
	/// offset 001C (4 bytes)
	/// if it is set then there's a twice is likely chance that this affix
	/// will be generated than if it's not
	bool32_t double_chance;
	/// offset 0020 (4 bytes)
	/// cursed affixes are never applied to items sold in town and also have
	/// lower probability to be applied in other cases.
	bool32_t not_cursed;
	/// offset 0024 (4 bytes)
	int min_price;
	/// offset 0028 (4 bytes)
	int max_price;
	/// offset 002C (4 bytes)
	int cost_multiplier;
} ItemAffixData;

/// Lighting represents a light source.
///
/// PSX def:
/// typedef struct LightListStruct {
///    char _lx;
///    char _ly;
///    unsigned short _lradius;
///    char _lid;
///    unsigned char _ldel;
///    unsigned char _lunflag;
///    char _lunx;
///    char _luny;
///    char _lunr;
///    char _xoff;
///    char _yoff;
///    unsigned char _lflags;
/// } LightListStruct;
///
/// size = 0x34
typedef struct {
	/// offset: 0000 (4 bytes)
	int x;
	/// offset: 0004 (4 bytes)
	int y;
	/// offset: 0008 (4 bytes)
	int light_radius;
	/// offset: 000C (4 bytes)
	int vision_id;
	/// offset: 0010 (4 bytes)
	bool32_t inactive;
	/// offset: 0014 (4 bytes)
	bool32_t visible;
	/// offset: 001C (4 bytes)
	int x_prev;
	/// offset: 0020 (4 bytes)
	int y_prev;
	/// offset: 0024 (4 bytes)
	int light_radius_prev;
	/// offset: 0028 (4 bytes)
	int x_offset;
	/// offset: 002C (4 bytes)
	int y_offset;
	/// offset: 0030 (4 bytes)
	uint32_t flags;
} Lighting;

/// MenuItem is a game menu item.
///
/// size = 0xC
typedef struct {
	/// offset: 0000 (4 bytes)
	uint32_t flags;
	/// offset: 0004 (4 bytes)
	char *name;
	/// offset: 0008 (4 bytes)
	void (*func)(bool32_t a1);
} MenuItem;

/// MissileGraphicData specifies the different missile animation graphics.
///
/// size = 0xEC
typedef struct {
	/// offset 0000 (1 bytes)
	/// Missile graphic ID.
	missile_graphic_id missile_graphic_id;
	/// offset 0001 (1 bytes)
	/// Number of animations.
	int8_t nanims;
	/// offset 0004 (4 bytes)
	/// CL2 image name.
	char *cl2_name;
	/// offset 0008 (4 bytes)
	/// Missile graphics flags.
	uint32_t flags;
	/// offset 000C (64 bytes)
	/// Map from orientation to CL2 buffer.
	void *cl2_from_orientation[16];
	/// offset 004C (16 bytes)
	/// Map from orientation to animation speed.
	int8_t anim_speed_from_orientation[16];
	/// offset 005C (16 bytes)
	/// Map from orientation to last frame (frame_num+1)
	int8_t last_frame_from_orientation[16];
	/// offset 006C (64 bytes)
	/// Map from orientation to frame width.
	int32_t frame_width_from_orientation[16];
	/// offset 00AC (64 bytes)
	/// X offset to the left side used for tile alignment.
	int32_t x_offset_from_orientation[16];
} MissileGraphicData;

/// An MPQHeader is the header of an MPQ archive.
///
/// size = 0x20
typedef struct {
	/// offset: 0000 (4 bytes)
	/// Magic signature; "MPQ\x1A"
	uint8_t magic[4];
	/// offset: 0004 (4 bytes)
	/// Size in bytes of the MPQ header.
	uint32_t hdr_size;
	/// offset: 0008 (4 bytes)
	/// Size in bytes of the MPQ archive.
	uint32_t archive_size;
	/// offset: 000C (2 bytes)
	/// MPQ format version.
	uint16_t format_version;
	/// offset: 000E (2 bytes)
	/// Sector size exponent; sectorSize = 512 * 2^SectorSizeExp.
	uint16_t sector_size_exp;
	/// offset: 0010 (4 bytes)
	/// Offset to the start of the hash table.
	uint32_t hash_table_offset;
	/// offset: 0014 (4 bytes)
	/// Offset to the start of the block table.
	uint32_t block_table_offset;
	/// offset: 0018 (4 bytes)
	/// Number of hash table entires.
	uint32_t hash_count;
	/// offset: 001C (4 bytes)
	/// Number of block table entires.
	uint32_t block_count;
} MPQHeader;

/// NarratorBook specifies the speech IDs of each dungeon type narrator book for
/// a player class.
///
/// size = 0xC
typedef struct {
	/// offset: 0000 (4 bytes)
	speech_id dlvl4_speech_id;
	/// offset: 0004 (4 bytes)
	speech_id dlvl8_speech_id;
	/// offset: 0008 (4 bytes)
	speech_id dlvl12_speech_id;
} NarratorBook;

/// ObjectData describes basic properties of game objects.
///
/// PSX def:
///    typedef struct ObjDataStruct {
///       char oload;
///       char ofindex;
///       char ominlvl;
///       char omaxlvl;
///       char olvltype;
///       char otheme;
///       char oquest;
///       unsigned char oAnimFlag;
///       short oAnimDelay;
///       short oAnimLen;
///       unsigned char oSolidFlag;
///       unsigned char oMissFlag;
///       unsigned char oLightFlag;
///       char oBreak;
///       char oSelFlag;
///       unsigned char oTrapFlag;
///    } ObjDataStruct;
///
/// size = 0x2C
typedef struct {
	/// offset: 0000 (1 bytes)
	/// TODO: define object_load enum
	int8_t object_load;
	/// offset: 0001 (1 bytes)
	object_graphic_id object_graphic_id;
	/// offset: 0002 (1 bytes)
	int8_t dlvl_min;
	/// offset: 0003 (1 bytes)
	int8_t dlvl_max;
	/// offset: 0004 (1 bytes)
	dungeon_type dtype;
	/// offset: 0005 (1 bytes)
	theme_id theme_id;
	/// offset: 0006 (1 bytes)
	quest_id quest_id;
	/// offset: 0008 (4 bytes)
	bool32_t animated;
	/// offset: 000C (4 bytes)
	/// specifies the number of game ticks per frame, or first frame if not animated.
	int32_t ticks_per_frame;
	/// offset: 0010 (4 bytes)
	int32_t nframes;
	/// offset: 0014 (4 bytes)
	int32_t frame_width;
	/// offset: 0018 (4 bytes)
	bool32_t collision;
	/// offset: 001C (4 bytes)
	bool32_t missile_can_pass;
	/// offset: 0020 (4 bytes)
	bool32_t has_light;
	/// offset: 0024 (1 bytes)
	bool8_t hittable;
	/// offset: 0025 (1 bytes)
	/// TODO: define object_interact enum
	int8_t object_interact;
	/// offset: 0028 (4 bytes)
	bool32_t possible_traphole;
} ObjectData;

/// PacketHeader is the header of a network game synchronization packet.
///
/// PSX def:
///    typedef struct TPktHdr {
///       unsigned char px;
///       unsigned char py;
///       unsigned char targx;
///       unsigned char targy;
///       unsigned long php;
///       unsigned long pmhp;
///       unsigned char bstr;
///       unsigned char bmag;
///       unsigned char bdex;
///       unsigned short wCheck;
///       unsigned short wLen;
///    } TPktHdr;
///
/// size = 0x13
typedef struct {
	/// offset: 0000 (1 bytes)
	int8_t x;
	/// offset: 0001 (1 bytes)
	int8_t y;
	/// offset: 0002 (1 bytes)
	int8_t target_x;
	/// offset: 0003 (1 bytes)
	int8_t target_y;
	/// offset: 0004 (4 bytes)
	int hp_cur;
	/// offset: 0008 (4 bytes)
	int hp_max;
	/// offset: 000C (1 bytes)
	int8_t str_base;
	/// offset: 000D (1 bytes)
	int8_t mag_base;
	/// offset: 000E (1 bytes)
	int8_t dex_base;
	/// offset: 000F (2 bytes)
	/// Contains the magic value 'ip' (0x6970).
	uint16_t pkt_type;
	/// offset: 0011 (2 bytes)
	int16_t len;
} PacketHeader;

/// Packet is a network game synchronization packet.
///
/// PSX def:
///    typedef struct TPkt {
///       struct TPktHdr hdr;
///       unsigned char body[492];
///    } TPkt;
///
/// size = 0x200
typedef struct {
	/// offset: 0000 (19 bytes)
	PacketHeader hdr;
	/// offset: 0013 (493 bytes)
	uint8_t data[493];
} Packet;

/// PanelButton specifies the position and dimensions of a panel button.
///
/// size = 0x14
typedef struct {
	/// offset: 0000 (4 bytes)
	int x;
	/// offset: 0004 (4 bytes)
	int y;
	/// offset: 0008 (4 bytes)
	int width;
	/// offset: 000C (4 bytes)
	int height;
	/// offset: 0010 (4 bytes)
	int unused;
} PanelButton;

/// PathNode is a node of a path constructed by the path finding algorithm.
///
/// PSX def:
///    typedef struct tagPATHNODE {
///       char f;
///       char h;
///       char g;
///       int x;
///       int y;
///       struct tagPATHNODE* Parent;
///       struct tagPATHNODE* Child[8];
///       struct tagPATHNODE* NextNode;
///    } tagPATHNODE, PATHNODE;
///
/// size = 0x34
typedef struct PathNode {
	/// offset 0000 (1 bytes)
	/// f(n) = g(n) + h(n)
	int8_t f;
	/// offset 0001 (1 bytes)
	/// heuristic cost to goal.
	int8_t h;
	/// offset 0002 (1 bytes)
	/// cost from start to n.
	int8_t g;
	/// offset 0004 (4 bytes)
	int x;
	/// offset 0008 (4 bytes)
	int y;
	/// offset 000C (4 bytes)
	struct PathNode *parent;
	/// offset 0010 (32 bytes)
	struct PathNode *children[8];
	/// offset 0030 (4 bytes)
	struct PathNode *next;
} PathNode;

/// A Point is an X, Y coordinate pair. The axes increase right and down.
typedef struct {
	/// offset: 0000 (4 bytes)
	int32_t x;
	/// offset: 0004 (4 bytes)
	int32_t y;
} Point;

/// A Portal represents a portal between two levels.
///
/// PSX def:
///    typedef struct DPortal {
///       unsigned char x;
///       unsigned char y;
///       unsigned char level;
///       unsigned char ltype;
///       unsigned char setlvl;
///    } DPortal;
typedef struct {
	int8_t x;
	int8_t y;
	int8_t dlvl;
	dungeon_type dtype;
	quest_level quest_lvl;
} Portal;

/// Quest describes in-game state of a quest.
///
/// PSX def:
///     typedef struct QuestStruct {
///        unsigned char _qlevel;
///        unsigned char _qtype;
///        unsigned char _qactive;
///        unsigned char _qlvltype;
///        int _qtx;
///        int _qty;
///        unsigned char _qslvl;
///        unsigned char _qidx;
///        unsigned char _qmsg;
///        unsigned char _qvar1;
///        unsigned char _qvar2;
///        unsigned char _qlog;
///        unsigned char pad_for_laz;
///     } QuestStruct;
///
/// size = 0x18
typedef struct {
	/// offset: 0000 (1 bytes)
	int8_t dlvl;
	/// offset: 0001 (1 bytes)
	quest_id quest_id;
	/// offset: 0002 (1 bytes)
	/// TODO: define quest_active enum
	int8_t quest_active;
	/// offset: 0003 (1 bytes)
	dungeon_type dtype;
	/// offset: 0004 (4 bytes)
	int32_t enterance_x;
	/// offset: 0008 (4 bytes)
	int32_t enterance_y;
	/// offset: 000C (1 bytes)
	int8_t quest_level;
	/// offset: 000D (1 bytes)
	quest_level_id quest_level_id;
	/// offset: 000E (1 bytes)
	speech_id speech_id;
	/// offset: 000F (1 bytes)
	int8_t var1;
	/// offset: 0010 (1 bytes)
	int8_t var2;
	/// offset: 0014 (4 bytes)
	bool32_t speech_spoken;
} Quest;

/// QuestData describes the basic properties and activation conditions of quests.
///
/// PSX def:
///    typedef struct QuestData {
///       unsigned char _qdlvl;
///       char _qdmultlvl;
///       unsigned char _qlvlt;
///       unsigned char _qdtype;
///       unsigned char _qdrnd;
///       unsigned char _qslvl;
///       unsigned char _qflags;
///       int _qdmsg;
///       int _qlstr;
///    } QuestData;
///
/// size = 0x14
typedef struct {
	/// offset: 0000 (1 bytes)
	int8_t dlvl_single;
	/// offset: 0001 (1 bytes)
	int8_t dlvl_multi;
	/// offset: 0002 (1 bytes)
	dungeon_type dtype;
	/// offset: 0003 (1 bytes)
	quest_id quest_id;
	/// offset: 0005 (1 bytes)
	quest_level quest_level;
	/// offset: 0008 (1 bytes)
	bool8_t multiplayer;
	/// offset: 000C (4 bytes)
	speech_id  speech_id;
	/// offset: 0010 (4 bytes)
	char *name;
} QuestData;

/// Rect specifies a rectangluar area of the map.
typedef struct {
	Coord min;
	Coord max;
} Rect;

/// Rectangle specifies a rectangluar area of the screen.
///
/// size = 0x10
typedef struct {
	/// offset: 0000 (4 bytes)
	int x;
	/// offset: 0004 (4 bytes)
	int y;
	/// offset: 0008 (4 bytes)
	int width;
	/// offset: 000C (4 bytes)
	int height;
} Rectangle;

/// ScreenRow represents a single horizontal line of pixels on the screen.
///
/// size = 0x300
typedef struct {
	/// offset 0000 (64 bytes)
	uint8_t col_unused_1[64];
	/// offset 0040 (640 bytes)
	uint8_t pixels[640];
	/// offset 02C0 (64 bytes)
	uint8_t col_unused_2[64];
} ScreenRow;

/// Screen represents the pixels of the screen.
///
/// size = 0x7B000
typedef struct {
	/// offset 00000000 (122880 bytes)
	ScreenRow row_unused_1[160];
	/// offset 0001E000 (368640 bytes)
	ScreenRow row[480];
	/// offset 00078000 (12288 bytes)
	ScreenRow row_unused_2[16];
} Screen;

/// A Shadow contains the shadows for a 2x2 block of base tile IDs.
///
/// PSX def:
///    typedef struct ShadowStruct {
///       unsigned char strig;
///       unsigned char s1;
///       unsigned char s2;
///       unsigned char s3;
///       unsigned char nv1;
///       unsigned char nv2;
///       unsigned char nv3;
///    } ShadowStruct;
///
/// TODO: Figure out how to fix broken links. Requires graphics files, which may
/// not be put online. Perhaps, add a script to view locally.
///
/// References:
///    * https://github.com/sanctuary/graphics/blob/master/l1/tiles/base.md
///    * https://github.com/sanctuary/graphics/blob/master/l2/tiles/base.md
typedef struct {
	/// 2x2 block of base tile IDs.
	l1_tile_id base_bottom;
	l1_tile_id base_top;
	l1_tile_id base_right;
	l1_tile_id base_left;
	/// replacement shadow tile IDs.
	l1_tile_id shadow_top;
	l1_tile_id shadow_right;
	l1_tile_id shadow_left;
} Shadow;

/// SoundFile represents a WAV sound file.
///
/// PSX def:
///    typedef struct TSnd {
///    } TSnd;
///
/// size = 0x28
typedef struct {
	/// offset 0000 (18 bytes)
	WAVEFORMATEX fmt;
	/// offset 0014 (4 bytes)
	int32_t len;
	/// offset 0018 (4 bytes)
	int32_t offset;
	/// offset 001C (4 bytes)
	char *sound_path;
	/// offset 0020 (4 bytes)
	/// direct sound buffer.
	IDirectSoundBuffer *DSB;
	/// offset 0024 (4 bytes)
	/// start tick count.
	uint32_t start_tc;
} SoundFile;

/// SfxData contains the data associated with a sound effect.
///
/// size = 0x9
typedef struct {
	/// offset: 0000 (1 bytes)
	uint8_t sfx_flag;
	/// offset: 0001 (4 bytes)
	char *sound_path;
	/// offset: 0005 (4 bytes)
	SoundFile *sound_file;
} SfxData;

/// SpeechData specifies the text and sound of a speech.
///
/// PSX ref:
///    typedef struct TextDataStruct {
///        int txtstr;
///        unsigned char scrlltxt;
///        unsigned char txtspd;
///        int sfxnr;
///    } TextDataStruct;
///
/// size = 0x10
typedef struct {
	/// offset: 0000 (4 bytes)
	char *text;
	/// offset: 0004 (4 bytes)
	bool32_t display_text;
	/// offset: 0008 (4 bytes)
	int32_t speed;
	/// offset: 000C (4 bytes)
	sfx_id sfx_id;
} SpeechData;

/// Stats specifies character statistics (i.e. strength, magic, dexterity,
/// vitality).
///
/// size = 0x10
typedef struct {
	/// offset: 0000 (4 bytes)
	int32_t str;
	/// offset: 0004 (4 bytes)
	int32_t mag;
	/// offset: 0008 (4 bytes)
	int32_t dex;
	/// offset: 000C (4 bytes)
	int32_t vit;
} Stats;

/// Stats_i16 specifies character statistics (i.e. strength, magic, dexterity,
/// vitality).
///
/// size = 0x8
typedef struct {
	/// offset: 0000 (2 bytes)
	int16_t str;
	/// offset: 0002 (2 bytes)
	int16_t mag;
	/// offset: 0004 (2 bytes)
	int16_t dex;
	/// offset: 0006 (2 bytes)
	int16_t vit;
} Stats_i16;

/// A Tile consists of four dungeon pieces (top, right, left, bottom), forming a
/// square.
///
///           top
///
///            /\
///    left   /\/\   right
///           \/\/
///            \/
///
///          bottom
typedef struct {
	/// Dungeon piece ID at the top of the tile.
	uint16_t top;
	/// Dungeon piece ID at the right of the tile.
	uint16_t right;
	/// Dungeon piece ID at the left of the tile.
	uint16_t left;
	/// Dungeon piece ID at the bottom of the tile.
	uint16_t bottom;
} Tile;

struct TMsg;

/// TMsgHeader represents the header of a timed message.
typedef struct {
	struct TMsg *next;
	uint32_t start_tc;
	uint8_t len;
} TMsgHeader;

/// TMsg represents a timed message.
typedef struct TMsg {
	TMsgHeader hdr;
	/// The size of msg is >= 3 and is dynamically allocated.
	uint8_t data[3];
} TMsg;

/// UiInfo specifies callback functions for the character selection user
/// interface.
///
/// size = 0x50
typedef struct {
	/// offset: 0000 (4 bytes)
	/// size of UiInfo struct.
	int size;
	/// offset: 0008 (4 bytes)
	HWND hFrameWnd;
	/// TODO: Fill in the correct function signatures below.
	/// offset: 000C (4 bytes)
	void (*UiArtCallback)();
	/// offset: 0010 (4 bytes)
	void (*UiAuthCallback)();
	/// offset: 0014 (4 bytes)
	void (*UiCreateGameCallback)();
	/// offset: 0018 (4 bytes)
	void (*UiDrawDescCallback)();
	/// offset: 0020 (4 bytes)
	void (*UiMessageBoxCallback)();
	/// offset: 0024 (4 bytes)
	void (*UiSoundCallback)();
	/// offset: 002C (4 bytes)
	void (*UiGetDataCallback)();
	/// offset: 0030 (4 bytes)
	void (*UiCategoryCallback)();
	/// offset: 003C (4 bytes)
	void (*UiProfileCallback)();
	/// offset: 0040 (4 bytes)
	void (*UiProfileGetString)();
	/// offset: 0044 (4 bytes)
	void (*UiProfileDraw)();
	/// offset: 0048 (4 bytes)
	void (*mainmenu_select_hero_dialog)();
	/// offset: 004C (4 bytes)
	void (*mainmenu_create_hero)();
} UiInfo;

/// UniqueItemData describes the properties and effects of a unique item.
///
/// size = 0x54
typedef struct {
	/// offset 0000 (4 bytes)
	char *name;
	/// offset 0004 (1 bytes)
	unique_base_item  unique_base_item;
	/// offset 0005 (1 bytes)
	int8_t quality_lvl;
	/// offset 0006 (1 bytes)
	int8_t neffects;
	/// offset 0008 (4 bytes)
	int32_t gold_price;
	/// offset 000C (72 bytes)
	ItemEffect effects[6];
} UniqueItemData;

/// UserInfo describes the selected character.
///
/// size = 0x10
typedef struct {
	/// offset: 0000 (4 bytes)
	int size;
	/// offset: 0004 (4 bytes)
	char *char_name;
	/// offset: 0008 (4 bytes)
	char *player_description;
	/// offset: 000C (4 bytes)
	int unknown_000C;
} UserInfo;

/// A Warp is an entrance that connects two levels of the map.
///
/// size = 0x10
typedef struct {
	/// offset: 0000 (4 bytes)
	/// X-coordinate of the entrance.
	int32_t entrance_x;
	/// offset: 0004 (4 bytes)
	/// Y-coordinate of the entrance.
	int32_t entrance_y;
	/// offset: 0008 (4 bytes)
	interface_mode interface_mode; // TODO: validate that this field is actualy used for interface_mode.
	/// offset: 000C (4 bytes)
	/// Dungeon level of the target map.
	int32_t dlvl_next;
} Warp;

#endif // STRUCTS_H
