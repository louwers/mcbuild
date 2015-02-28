#pragma once

////////////////////////////////////////////////////////////////////////////////
//// Protocol IDs

#define PROTO_NONE   0x00000000
#define PROTO_1_8_1  0x00010801

////////////////////////////////////////////////////////////////////////////////
//// Protocol Messages

#define STATE_IDLE     0
#define STATE_STATUS   1
#define STATE_LOGIN    2
#define STATE_PLAY     3

#define SI(x) ((0x00<<24)|(0x##x))
#define CI(x) ((0x10<<24)|(0x##x))
#define SS(x) ((0x01<<24)|(0x##x))
#define CS(x) ((0x11<<24)|(0x##x))
#define SL(x) ((0x02<<24)|(0x##x))
#define CL(x) ((0x12<<24)|(0x##x))
#define SP(x) ((0x03<<24)|(0x##x))
#define CP(x) ((0x13<<24)|(0x##x))

#define PID(x)     ((x)&0xffffff)
#define PCLIENT(x) (((x)&0x10000000)!=0)
#define PSTATE(x)  (((x)>>24)&0x0f)

// Handshakes

#define CI_Handshake            CI(00)

// Status Query

#define SS_Response             SS(00)
#define SS_PingResponse         SS(01)

#define CS_Request              CS(00)
#define CS_PingRequest          CS(01)

// Login Process

#define SL_Disconnect           SL(00)
#define SL_EncryptionRequest    SL(01)
#define SL_LoginSuccess         SL(02)
#define SL_SetCompression       SL(03)

#define CL_LoginStart           CL(00)
#define CL_EncryptionResponse   CL(01)

// Play

#define SP_KeepAlive            SP(00)
#define SP_JoinGame             SP(01)
#define SP_ChatMessage          SP(02)
#define SP_TimeUpdate           SP(03)
#define SP_EntityEquipment      SP(04)
#define SP_SpawnPosition        SP(05)
#define SP_UpdateHealth         SP(06)
#define SP_Respawn              SP(07)
#define SP_PlayerPositionLook   SP(08)
#define SP_HeldItemChange       SP(09)
#define SP_UseBed               SP(0a)
#define SP_Animation            SP(0b)
#define SP_SpawnPlayer          SP(0c)
#define SP_CollectItem          SP(0d)
#define SP_SpawnObject          SP(0e)
#define SP_SpawnMob             SP(0f)
#define SP_SpawnPainting        SP(10)
#define SP_SpawnExperienceOrb   SP(11)
#define SP_EntityVelocity       SP(12)
#define SP_DestroyEntities      SP(13)
#define SP_Entity               SP(14)
#define SP_EntityRelMove        SP(15)
#define SP_EntityLook           SP(16)
#define SP_EntityLookRelMove    SP(17)
#define SP_EntityTeleport       SP(18)
#define SP_EntityHeadLook       SP(19)
#define SP_EntityStatus         SP(1a)
#define SP_AttachEntity         SP(1b)
#define SP_EntityMetadata       SP(1c)
#define SP_EntityEffect         SP(1d)
#define SP_RemoveEntityEffect   SP(1e)
#define SP_SetExperience        SP(1f)
#define SP_EntityProperties     SP(20)
#define SP_ChunkData            SP(21)
#define SP_MultiBlockChange     SP(22)
#define SP_BlockChange          SP(23)
#define SP_BlockAction          SP(24)
#define SP_BlockBreakAnimation  SP(25)
#define SP_MapChunkBulk         SP(26)
#define SP_Explosion            SP(27)
#define SP_Effect               SP(28)
#define SP_SoundEffect          SP(29)
#define SP_Particle             SP(2a)
#define SP_ChangeGameState      SP(2b)
#define SP_SpawnGlobalEntity    SP(2c)
#define SP_OpenWindow           SP(2d)
#define SP_CloseWindow          SP(2e)
#define SP_SetSlot              SP(2f)
#define SP_WindowItems          SP(30)
#define SP_WindowProperty       SP(31)
#define SP_ConfirmTransaction   SP(32)
#define SP_UpdateSign           SP(33)
#define SP_Maps                 SP(34)
#define SP_UpdateBlockEntity    SP(35)
#define SP_SignEditorOpen       SP(36)
#define SP_Statistics           SP(37)
#define SP_PlayerListItem       SP(38)
#define SP_PlayerAbilities      SP(39)
#define SP_TabComplete          SP(3a)
#define SP_ScoreboardObjective  SP(3b)
#define SP_UpdateScore          SP(3c)
#define SP_DisplayScoreboard    SP(3d)
#define SP_Teams                SP(3e)
#define SP_PluginMessage        SP(3f)
#define SP_Disconnect           SP(40)
#define SP_ServerDifficulty     SP(41)
#define SP_CombatEffect         SP(42)
#define SP_Camera               SP(43)
#define SP_WorldBorder          SP(44)
#define SP_Title                SP(45)
#define SP_SetCompression       SP(46)
#define SP_PlayerListHeader     SP(47)
#define SP_ResourcePackSent     SP(48)
#define SP_UpdateEntityNbt      SP(49)

#define CP_KeepAlive            CP(00)
#define CP_ChatMessage          CP(01)
#define CP_UseEntity            CP(02)
#define CP_Player               CP(03)
#define CP_PlayerPosition       CP(04)
#define CP_PlayerLook           CP(05)
#define CP_PlayerPositionLook   CP(06)
#define CP_PlayerDigging        CP(07)
#define CP_PlayerBlockPlacement CP(08)
#define CP_HeldItemChange       CP(09)
#define CP_Animation            CP(0a)
#define CP_EntityAction         CP(0b)
#define CP_SteerVehicle         CP(0c)
#define CP_CloseWindow          CP(0d)
#define CP_ClickWindow          CP(0e)
#define CP_ConfirmTransaction   CP(0f)
#define CP_CreativeInventoryAct CP(10)
#define CP_EnchantItem          CP(11)
#define CP_UpdateSign           CP(12)
#define CP_PlayerAbilities      CP(13)
#define CP_TabComplete          CP(14)
#define CP_ClientSettings       CP(15)
#define CP_ClientStatus         CP(16)
#define CP_PluginMessage        CP(17)
#define CP_Spectate             CP(18)
#define CP_ResourcePackStatus   CP(19)

#define MAXPACKETTYPES          0x100

////////////////////////////////////////////////////////////////////////////////
// Block IDs

#define I_ITEM   (1<<0)         // the ID is an item, i.e. cannot be placed as a block
#define I_MTYPE  (1<<1)         // the metadata defines the subtype (i.e. color or material), 
                                // unlike MPOS, this is stored in the inventory slots
#define I_MPOS   (1<<2)         // the metadata controls orientation/position - for placed blocks only
#define I_MSTATE (1<<3)         // the metadata contains state information - something not dependent on placement
#define I_NSTACK (1<<4)         // Item does not stack (or stack size=1)
#define I_S16    (1<<5)         // item stacks only by 16

typedef struct _item_id {
    const char * name;
    uint16_t     flags;
    const char * mname[16];
} item_id;

static const item_id ITEMS[] = {
    [0x00] = { "Air" },
    [0x01] = { "Stone" }, //new metatypes in 1.8
    [0x02] = { "Grass" },
    [0x03] = { "Dirt", I_MTYPE,
               { "Normal", "Grassless", "Podzol" }, },
    [0x04] = { "Cobblestone" },
    [0x05] = { "Woodplanks", I_MTYPE,
               { "Oak", "Spruce", "Birch", "Jungle", "Acacia", "Dark Oak" }, },
    [0x06] = { "Sapling", I_MTYPE,
               { "Oak", "Spruce", "Birch", "Jungle", "Acacia", "Dark Oak" }, },
    [0x07] = { "Bedrock" },
    [0x08] = { "Waterflow" },
    [0x09] = { "Water" },
    [0x0a] = { "Lavaflow" },
    [0x0b] = { "Lava" },
    [0x0c] = { "Sand", I_MTYPE,
               { "Normal", "Red", }, },
    [0x0d] = { "Gravel" },
    [0x0e] = { "Gold ore" },
    [0x0f] = { "Iron ore" },

    [0x10] = { "Coal ore" },
    [0x11] = { "Wood", I_MTYPE|I_MPOS,        
               { "Oak UD", "Spruce UD", "Birch UD", "Jungle UD",
                 "Oak EW", "Spruce EW", "Birch EW", "Jungle EW",
                 "Oak NS", "Spruce NS", "Birch NS", "Jungle NS",
                 "Oak bark", "Spruce bark", "Birch bark", "Jungle bark", }, },
    [0x12] = { "Leaves", I_MTYPE|I_MSTATE,
               { "Oak", "Spruce", "Birch", "Jungle",
                 "Oak ND", "Spruce ND", "Birch ND", "Jungle ND",
                 "Oak CD", "Spruce CD", "Birch CD", "Jungle CD",
                 "Oak CD ND", "Spruce CD ND", "Birch CD ND", "Jungle CD ND", }, },
    [0x13] = { "Sponge" },
    [0x14] = { "Glass" },
    [0x15] = { "Lapis ore" },
    [0x16] = { "Lapis block" },
    [0x17] = { "Dispenser", I_MPOS },
    [0x18] = { "Sandstone", I_MTYPE,
               { "Normal", "Chiseled", "Smooth", }, },
    [0x19] = { "Noteblock" },
    [0x1a] = { "Bed", I_MPOS },
    [0x1b] = { "Powered Rail", I_MPOS },
    [0x1c] = { "Detector Rail", I_MPOS },
    [0x1d] = { "Sticky Piston", I_MPOS },
    [0x1e] = { "Cobweb", },
    [0x1f] = { "Tallgrass", },

    [0x20] = { "Deadbush" },
    [0x21] = { "Piston", I_MPOS },
    [0x22] = { "Piston Head", I_MPOS },
    [0x23] = { "Wool", I_MTYPE, 
               { "White", "Orange", "Magenta", "LBlue",
                 "Yellow", "Lime", "Pink", "Grey",
                 "LGrey", "Cyan", "Purple", "Blue",
                 "Brown", "Green", "Red", "Black", }, },
    [0x24] = { "Pushed block", },
    [0x25] = { "Dandelion", },
    [0x26] = { "Flower", I_MTYPE,
               { "Poppy", "Blue orchid", "Allium", "Azure Bluet", 
                 "Red Tulip", "Orange Tulip", "White Tulip", "Pink Tulip",
                 "Oxeye Daisy", }, },
    [0x27] = { "Brown Mushroom" },
    [0x28] = { "Red Mushroom" },
    [0x29] = { "Gold Block" },
    [0x2a] = { "Iron Block" },
    [0x2b] = { "Double Stone Slab", I_MTYPE, 
               { "Stone", "Sandstone", "Wood", "Cobble",
                 "Brick", "Stone Brick", "Netherbrick", "Quartz",
                 "Smooth Stone", "Smooth Sandstone", "Tile Quartz", }, },
    [0x2c] = { "Stone Slab", I_MTYPE,
               { "Stone", "Sandstone", "Wood", "Cobble",
                 "Brick", "Stone Brick", "Netherbrick", "Quartz",
                 "Smooth Stone", "Smooth Sandstone", "Tile Quartz", }, },
    [0x2d] = { "Brick" },
    [0x2e] = { "TNT" },
    [0x2f] = { "Bookshelf" },

    [0x30] = { "Mossy Cobblestone" },
    [0x31] = { "Obsidian" },
    [0x32] = { "Torch", I_MPOS },
    [0x33] = { "Fire", I_MSTATE },
    [0x34] = { "Spawner" },
    [0x35] = { "Wooden Stairs", I_MPOS },
    [0x36] = { "Chest", I_MPOS },
    [0x37] = { "Redstone Wire", I_MPOS },
    [0x38] = { "Diamond Ore" },
    [0x39] = { "Diamond Block" },
    [0x3a] = { "Workbench" },
    [0x3b] = { "Wheat" },
    [0x3c] = { "Farmland" },
    [0x3d] = { "Furnace", I_MPOS },
    [0x3e] = { "Lit Furnace", I_MPOS },
    [0x3f] = { "Sign", I_MPOS },

    [0x40] = { "Wooden Door", I_MPOS },
    [0x41] = { "Ladder", I_MPOS },
    [0x42] = { "Rail", I_MPOS },
    [0x43] = { "Cobblestone Stairs", I_MPOS },
    [0x44] = { "Wall Sign", I_MPOS },
    [0x45] = { "Lever", I_MPOS },
    [0x46] = { "Pressure Plate" },
    [0x47] = { "Iron Door", I_MPOS },
    [0x48] = { "Wooden Pressure Plate" },
    [0x49] = { "Redstone Ore" },
    [0x4a] = { "Glowing Redstone Ore" },
    [0x4b] = { "Redstone Torch, Inactive", I_MPOS },
    [0x4c] = { "Redstone Torch, Active", I_MPOS },
    [0x4d] = { "Stone Button", I_MPOS },
    [0x4e] = { "Snow Layer" },
    [0x4f] = { "Ice" },

    [0x50] = { "Snow" },
    [0x51] = { "Cactus" },
    [0x52] = { "Clay Block" },
    [0x53] = { "Sugar Cane" },
    [0x54] = { "Jukebox" },
    [0x55] = { "Fence" },
    [0x56] = { "Pumpkin" },
    [0x57] = { "Netherrack" },
    [0x58] = { "Soul Sand" },
    [0x59] = { "Glowstone Block" },
    [0x5a] = { "Portal", I_MPOS },
    [0x5b] = { "Jack-o-Lantern", I_MPOS },
    [0x5c] = { "Cake", I_MSTATE },
    [0x5d] = { "Repeater, Inactive", I_MPOS },
    [0x5e] = { "Repeater, Active", I_MPOS },
    [0x5f] = { "Stained Glass", I_MTYPE,
               { "White", "Orange", "Magenta", "LBlue",
                 "Yellow", "Lime", "Pink", "Grey",
                 "LGrey", "Cyan", "Purple", "Blue",
                 "Brown", "Green", "Red", "Black" }, },

    [0x60] = { "Trapdoor", I_MPOS },
    [0x61] = { "Silverfish Block", I_MTYPE,
               { "Stone", "Cobblestone", "Stonebrick", "Mossy Stonebrick",
                 "Cracked Stonebrick", "Chiseled Stonebrick" }, },
    [0x62] = { "Stonebrick", I_MTYPE,
               { "Normal", "Mossy", "Cracked", "Chiseled" }, },
    [0x63] = { "Brown Mushroom Block", I_MPOS,
               { "Pores only", "Cap NW", "Cap N", "Cap NE",
                 "Cap W", "Cap T", "Cap E", "Cap SW",
                 "Cap S", "Cap SE", "Stem", [14] = "Cap only", [15]="Stem only"}, },
    [0x64] = { "Red Mushroom Block", I_MPOS,
               { "Pores only", "Cap NW", "Cap N", "Cap NE",
                 "Cap W", "Cap T", "Cap E", "Cap SW",
                 "Cap S", "Cap SE", "Stem", [14] = "Cap only", [15]="Stem only"}, },
    [0x65] = { "Iron Bars" },
    [0x66] = { "Glass Pane" },
    [0x67] = { "Melon Block" },
    [0x68] = { "Pumpkin Stem" },
    [0x69] = { "Melon Stem" },
    [0x6a] = { "Vine", I_MPOS },
    [0x6b] = { "Fence Gate", I_MPOS|I_MSTATE,
               { "South cl", "West cl", "North cl", "East cl",
                 "South op", "West op", "North op", "East op" }, },
    [0x6c] = { "Brick Stairs", I_MPOS },
    [0x6d] = { "Stone Brick Stairs", I_MPOS },
    [0x6e] = { "Mycelium" },
    [0x6f] = { "Waterlily", I_MPOS },

    [0x70] = { "Nether Brick" },
    [0x71] = { "Nether Brick Fence" },
    [0x72] = { "Nether Brick Stairs", I_MPOS },
    [0x73] = { "Nether Wart", I_MSTATE },
    [0x74] = { "Enchantment Table" },
    [0x75] = { "Brewing Stand" },
    [0x76] = { "Cauldron", I_MSTATE },
    [0x77] = { "End Portal", I_MPOS },
    [0x78] = { "End Portal Block", I_MPOS },
    [0x79] = { "End Stone" },
    [0x7a] = { "Dragon Egg" },
    [0x7b] = { "Redstone Lamp" },
    [0x7c] = { "Redstone Lamp (lit)" },
    [0x7d] = { "Wooden Double Slab" },
    [0x7e] = { "Wooden Slab", I_MTYPE|I_MPOS,
               { "Oak", "Spruce", "Birch", "Jungle", "Acacia", "Dark Oak", NULL, NULL,
                 "Oak U", "Spruce U", "Birch U", "Jungle U", "Acacia U", "Dark Oak U", NULL, NULL, }, },
    [0x7f] = { "Cocoa", I_MSTATE },

    [0x80] = { "Sandstone Stairs", I_MPOS },
    [0x81] = { "Emerald Ore" },
    [0x82] = { "Ender Chest", I_MPOS },
    [0x83] = { "Tripwire Hook", I_MPOS|I_MSTATE },
    [0x84] = { "Tripwire", I_MPOS },
    [0x85] = { "Emerald Block" },
    [0x86] = { "Spruce Stairs", I_MPOS },
    [0x87] = { "Birch Stairs", I_MPOS },
    [0x88] = { "Jungle Stairs", I_MPOS },
    [0x89] = { "Command Block" },
    [0x8a] = { "Beacon" },
    [0x8b] = { "Cobblestone Wall" },
    [0x8c] = { "Flower Pot", I_MSTATE },
    [0x8d] = { "Carrots", I_MSTATE },
    [0x8e] = { "Potatoes", I_MSTATE },
    [0x8f] = { "Wooden Button", I_MPOS },

    [0x90] = { "Skull", I_MPOS|I_MSTATE },
    [0x91] = { "Anvil", I_MPOS },
    [0x92] = { "Trapped Chest", I_MPOS },
    [0x93] = { "Pressure Plate" },
    [0x94] = { "Pressure Plate (pressed)" },
    [0x95] = { "Comparator", I_MPOS },
    [0x96] = { "Comparator (powered)", I_MPOS },
    [0x97] = { "Daylight Detector" },
    [0x98] = { "Redstone Block" },
    [0x99] = { "Quartz Ore" },
    [0x9a] = { "Hopper", I_MPOS },
    [0x9b] = { "Quartz Block" },
    [0x9c] = { "Quartz Stairs", I_MPOS },
    [0x9d] = { "Activator Rail", I_MPOS },
    [0x9e] = { "Dropper", I_MPOS },
    [0x9f] = { "Hardened Clay", I_MTYPE, 
               { "White", "Orange", "Magenta", "LBlue",
                 "Yellow", "Lime", "Pink", "Grey",
                 "LGrey", "Cyan", "Purple", "Blue",
                 "Brown", "Green", "Red", "Black", }, },
    
    [0xa0] = { "Stained Glass Pane", I_MTYPE, 
               { "White", "Orange", "Magenta", "LBlue",
                 "Yellow", "Lime", "Pink", "Grey",
                 "LGrey", "Cyan", "Purple", "Blue",
                 "Brown", "Green", "Red", "Black", }, },
    [0xa1] = { "Leaves2", I_MTYPE|I_MSTATE,
               { "Acacia", "Dark Oak", NULL, NULL,
                 "Acacia ND", "Dark Oak ND", NULL, NULL,
                 "Acacia CD", "Dark Oak CD", NULL, NULL,
                 "Acacia CD ND", "Dark Oak CD ND", NULL, NULL, }, },
    [0xa2] = { "Wood2", I_MTYPE|I_MPOS,        
               { "Acacia UD", "Dark Oak UD", NULL, NULL,
                 "Acacia EW", "Dark Oak EW", NULL, NULL,
                 "Acacia NS", "Dark Oak NS", NULL, NULL,
                 "Acacia bark", "Dark Oak bark", NULL, NULL, }, },
    [0xa3] = { "Acacia Stairs", I_MPOS },
    [0xa4] = { "Dark Oak Stairs", I_MPOS },
    [0xa5] = { "Slime Block" },
    [0xa6] = { "Barrier" },
    [0xa7] = { "Iron Trapdoor", I_MPOS },
    [0xa8] = { "unused" },
    [0xa9] = { "unused" },
    [0xaa] = { "Hay Block", I_MPOS },
    [0xab] = { "Carpet", I_MTYPE, 
               { "White", "Orange", "Magenta", "LBlue",
                 "Yellow", "Lime", "Pink", "Grey",
                 "LGrey", "Cyan", "Purple", "Blue",
                 "Brown", "Green", "Red", "Black", }, },
    [0xac] = { "Hardened Clay" },
    [0xad] = { "Coal Block" },
    [0xae] = { "Packed Ice" },
    [0xaf] = { "Double Plant", I_MTYPE,
               { "Sunflower", "Lilac", "DblTallgrass", "Large Fern", 
                 "Rose Bush", "Peony", NULL, NULL, "Top" }, },

    [0x100] = { "Iron Shovel", I_ITEM|I_NSTACK },
    [0x101] = { "Iron Pickaxe", I_ITEM|I_NSTACK },
    [0x102] = { "Iron Axe", I_ITEM|I_NSTACK },
    [0x103] = { "Flint and Steel", I_ITEM|I_NSTACK },
    [0x104] = { "Apple", I_ITEM },
    [0x105] = { "Bow", I_ITEM|I_NSTACK },
    [0x106] = { "Arrow", I_ITEM },
    [0x107] = { "Coal", I_ITEM|I_MTYPE,
                { NULL, "Charcoal" }, },
    [0x108] = { "Diamond", I_ITEM },
    [0x109] = { "Iron Ingot", I_ITEM },
    [0x10a] = { "Gold Ingot", I_ITEM },
    [0x10b] = { "Iron Sword", I_ITEM },
    [0x10c] = { "Wooden Sword", I_ITEM|I_NSTACK },
    [0x10d] = { "Wooden Shovel", I_ITEM|I_NSTACK },
    [0x10e] = { "Wooden Pickaxe", I_ITEM|I_NSTACK },
    [0x10f] = { "Wooden Axe", I_ITEM|I_NSTACK },

    [0x110] = { "Stone Sword", I_ITEM|I_NSTACK },
    [0x111] = { "Stone Shovel", I_ITEM|I_NSTACK },
    [0x112] = { "Stone Pickaxe", I_ITEM|I_NSTACK },
    [0x113] = { "Stone Axe", I_ITEM|I_NSTACK },
    [0x114] = { "Diamond Sword", I_ITEM|I_NSTACK },
    [0x115] = { "Diamond Shovel", I_ITEM|I_NSTACK },
    [0x116] = { "Diamond Pickaxe", I_ITEM|I_NSTACK },
    [0x117] = { "Diamond Axe", I_ITEM|I_NSTACK },
    [0x118] = { "Stick", I_ITEM },
    [0x119] = { "Bowl", I_ITEM },
    [0x11a] = { "Mushroom Stew", I_ITEM|I_NSTACK },
    [0x11b] = { "Golden Sword", I_ITEM },
    [0x11c] = { "Golden Shovel", I_ITEM },
    [0x11d] = { "Golden Pickaxe", I_ITEM },
    [0x11e] = { "Golden Axe", I_ITEM },
    [0x11f] = { "String", I_ITEM },

    [0x120] = { "Feather", I_ITEM },
    [0x121] = { "Gunpowder", I_ITEM },
    [0x122] = { "Wooden Hoe", I_ITEM|I_NSTACK },
    [0x123] = { "Stone Hoe", I_ITEM|I_NSTACK },
    [0x124] = { "Iron Hoe", I_ITEM|I_NSTACK },
    [0x125] = { "Diamond Hoe", I_ITEM|I_NSTACK },
    [0x126] = { "Golden Hoe", I_ITEM|I_NSTACK },
    [0x127] = { "Wheat Seeds", I_ITEM },
    [0x128] = { "Wheat", I_ITEM },
    [0x129] = { "Bread", I_ITEM },
    [0x12a] = { "Leather Helmet", I_ITEM|I_NSTACK },
    [0x12b] = { "Leather Chestplate", I_ITEM|I_NSTACK },
    [0x12c] = { "Leather Leggings", I_ITEM|I_NSTACK },
    [0x12d] = { "Leather Boots", I_ITEM|I_NSTACK },
    [0x12e] = { "Chainmail Helmet", I_ITEM|I_NSTACK },
    [0x12f] = { "Chainmail Chestplate", I_ITEM|I_NSTACK },

    [0x130] = { "Chainmail Leggings", I_ITEM|I_NSTACK },
    [0x131] = { "Chainmail Boots", I_ITEM|I_NSTACK },
    [0x132] = { "Iron Helmet", I_ITEM|I_NSTACK },
    [0x133] = { "Iron Chestplate", I_ITEM|I_NSTACK },
    [0x134] = { "Iron Leggings", I_ITEM|I_NSTACK },
    [0x135] = { "Iron Boots", I_ITEM|I_NSTACK },
    [0x136] = { "Diamond Helmet", I_ITEM|I_NSTACK },
    [0x137] = { "Diamond Chestplate", I_ITEM|I_NSTACK },
    [0x138] = { "Diamond Leggings", I_ITEM|I_NSTACK },
    [0x139] = { "Diamond Boots", I_ITEM|I_NSTACK },
    [0x13a] = { "Golden Helmet", I_ITEM|I_NSTACK },
    [0x13b] = { "Golden Chestplate", I_ITEM|I_NSTACK },
    [0x13c] = { "Golden Leggings", I_ITEM|I_NSTACK },
    [0x13d] = { "Golden Boots", I_ITEM|I_NSTACK },
    [0x13e] = { "Flint", I_ITEM },
    [0x13f] = { "Porkchop", I_ITEM },

    [0x140] = { "Cooked Porkchop", I_ITEM },
    [0x141] = { "Painting", I_ITEM },
    [0x142] = { "Golden Apple", I_ITEM },
    [0x143] = { "Sign", I_ITEM|I_S16 },
    [0x144] = { "Wooden Door", I_ITEM|I_NSTACK },
    [0x145] = { "Bucket", I_ITEM },
    [0x146] = { "Water Bucket", I_ITEM|I_NSTACK },
    [0x147] = { "Lava Bucket", I_ITEM|I_NSTACK },
    [0x148] = { "Minecart", I_ITEM|I_NSTACK },
    [0x149] = { "Saddle", I_ITEM|I_NSTACK },
    [0x14a] = { "Iron Door", I_ITEM|I_NSTACK },
    [0x14b] = { "Redstone", I_ITEM },
    [0x14c] = { "Snowball", I_ITEM|I_S16 },
    [0x14d] = { "Boat", I_ITEM|I_NSTACK },
    [0x14e] = { "Leather", I_ITEM },
    [0x14f] = { "Milk Bucket", I_ITEM|I_NSTACK },

    [0x150] = { "Brick", I_ITEM },
    [0x151] = { "Clay Ball", I_ITEM|I_S16 },
    [0x152] = { "Reeds", I_ITEM },
    [0x153] = { "Paper", I_ITEM },
    [0x154] = { "Book", I_ITEM },
    [0x155] = { "Slime Ball", I_ITEM },
    [0x156] = { "Chest Minecart", I_ITEM|I_NSTACK },
    [0x157] = { "Furnace Minecart", I_ITEM|I_NSTACK },
    [0x158] = { "Egg", I_ITEM|I_S16 },
    [0x159] = { "Compass", I_ITEM|I_NSTACK },
    [0x15a] = { "Fishing Rod", I_ITEM|I_NSTACK },
    [0x15b] = { "Clock", I_ITEM|I_NSTACK },
    [0x15c] = { "Glowstone Dust", I_ITEM },
    [0x15d] = { "Fish", I_ITEM },
    [0x15e] = { "Cooked Fish", I_ITEM },
    [0x15f] = { "Dye", I_ITEM|I_MTYPE,
                { "Ink Sac", "Rose Red", "Cactus Green", "Cocoa Beans",
                  "Lapis Lazuli", "Purple", "Cyan", "L.Gray",
                  "Gray", "Pink", "Lime", "Dandelion Yellow",
                  "L.Blue", "Magenta", "Orange", "Bone Meal" }, },

    [0x160] = { "Bone", I_ITEM },
    [0x161] = { "Sugar", I_ITEM },
    [0x162] = { "Cake", I_ITEM },
    [0x163] = { "Bed", I_ITEM },
    [0x164] = { "Repeater", I_ITEM },
    [0x165] = { "Cookie", I_ITEM },
    [0x166] = { "Map", I_ITEM },
    [0x167] = { "Shears", I_ITEM },
    [0x168] = { "Melon", I_ITEM },
    [0x169] = { "Pumpkin Seeds", I_ITEM },
    [0x16a] = { "Melon Seeds", I_ITEM },
    [0x16b] = { "Raw Beef", I_ITEM },
    [0x16c] = { "Steak", I_ITEM },
    [0x16d] = { "Raw Chicken", I_ITEM },
    [0x16e] = { "Cooked Chicken", I_ITEM },
    [0x16f] = { "Rotten Flesh", I_ITEM },

    [0x170] = { "Ender Pearl", I_ITEM },
    [0x171] = { "Blaze Rod", I_ITEM },
    [0x172] = { "Ghast Tear", I_ITEM },
    [0x173] = { "Gold Nugget", I_ITEM },
    [0x174] = { "Nether Wart", I_ITEM },
    [0x175] = { "Potions", I_ITEM },
    [0x176] = { "Glass Bottle", I_ITEM },
    [0x177] = { "Spider Eye", I_ITEM },
    [0x178] = { "Fermented Eye", I_ITEM },
    [0x179] = { "Blaze Powder", I_ITEM },
    [0x17a] = { "Magma Cream", I_ITEM },
    [0x17b] = { "Brewing Stand", I_ITEM },
    [0x17c] = { "Cauldron", I_ITEM },
    [0x17d] = { "Ender Eye", I_ITEM },
    [0x17e] = { "Speckled Melon", I_ITEM },
    [0x17f] = { "Spawn Egg", I_ITEM },

    [0x180] = { "Exp Potion", I_ITEM },
    [0x181] = { "Fire Charge", I_ITEM },
    [0x182] = { "Book and Quill", I_ITEM },
    [0x183] = { "Written Book", I_ITEM },
    [0x184] = { "Emerald", I_ITEM },
    [0x185] = { "Item Frame", I_ITEM },
    [0x186] = { "Flower Pot", I_ITEM },
    [0x187] = { "Carrot", I_ITEM },
    [0x188] = { "Potato", I_ITEM },
    [0x189] = { "Baked Potato", I_ITEM },
    [0x18a] = { "Poisonous Potato", I_ITEM },
    [0x18b] = { "Empty Map", I_ITEM },
    [0x18c] = { "Golden Carrot", I_ITEM },
    [0x18d] = { "Mob Head", I_ITEM },
    [0x18e] = { "Carrot on a Stick", I_ITEM },
    [0x18f] = { "Nether Star", I_ITEM },

    [0x190] = { "Pumpkin Pie", I_ITEM },
    [0x191] = { "Fireworks", I_ITEM },
    [0x192] = { "Firework Charge", I_ITEM },
    [0x193] = { "Enchanted Book", I_ITEM },
    [0x194] = { "Comparator", I_ITEM },
    [0x195] = { "Netherbrick", I_ITEM },
    [0x196] = { "Quartz", I_ITEM },
    [0x197] = { "TNT Minecart", I_ITEM },
    [0x198] = { "Hopper Minecart", I_ITEM },

    [0x1a1] = { "Iron Horse Armor", I_ITEM },
    [0x1a2] = { "Golden Horse Armor", I_ITEM },
    [0x1a3] = { "Diamond Horse Armor", I_ITEM },
    [0x1a4] = { "Lead", I_ITEM },
    [0x1a5] = { "Name Tag", I_ITEM },
    [0x1a6] = { "Cmd Block Minecart", I_ITEM },

    [0x8d0] = { "Record 13", I_ITEM },
    [0x8d1] = { "Record Cat", I_ITEM },
    [0x8d2] = { "Record Blocks", I_ITEM },
    [0x8d3] = { "Record Chirp", I_ITEM },
    [0x8d4] = { "Record Far", I_ITEM },
    [0x8d5] = { "Record Mall", I_ITEM },
    [0x8d6] = { "Record Mellohi", I_ITEM },
    [0x8d7] = { "Record Stal", I_ITEM },
    [0x8d8] = { "Record Strad", I_ITEM },
    [0x8d9] = { "Record Ward", I_ITEM },
    [0x8da] = { "Record 11", I_ITEM },
    [0x8db] = { "Record Wait", I_ITEM },


    [0x8ff] = { NULL },
};

////////////////////////////////////////////////////////////////////////////////
// Entity Metadata

typedef enum {
    IllegalEntityType = -1,
    Entity = 0,
    LivingEntity,
    Ageable,
    ArmorStand,
    Human,
    Horse,
    Bat,
    Tameable,
    Ocelot,
    Wolf,
    Pig,
    Rabbit,
    Sheep,
    Villager,
    Enderman,
    Zombie,
    ZombiePigman,
    Blaze,
    Spider,
    CaveSpider,
    Creeper,
    Ghast,
    Slime,
    MagmaCube,
    Skeleton,
    Witch,
    IronGolem,
    Wither,
    Boat,
    Minecart,
    FurnaceMinecart,
    Item,
    Arrow,
    Firework,
    ItemFrame,
    EnderCrystal,
} EntityType;

static const char * METANAME[][32] = {
    [Entity] = {
        [0]  = "Flags",
        [1]  = "Air",
    },
    [LivingEntity] = {
        [0]  = "Flags",
        [1]  = "Air",
        [2]  = "Name tag",
        [3]  = "Always show name tag",
        [6]  = "Health",
        [7]  = "Potion effect color",
        [8]  = "Potion effect ambient",
        [9]  = "Number of arrows",
        [15] = "No AI",
    },
    [Ageable] = {
        [12] = "Age",
    },
    [ArmorStand] = {
        [10] = "Armor stand flags",
        [11] = "Head position",
        [12] = "Body position",
        [13] = "L arm position",
        [14] = "R arm position",
        [15] = "L leg position",
        [16] = "R leg position",
    },
    [Human] = {
        [10] = "Skin flags",
        [16] = "Hide cape",
        [17] = "Absorption hearts",
        [18] = "Score",
    },
    [Horse] = {
        [16] = "Horse flags",
        [19] = "Horse type",
        [20] = "Horse color",
        [21] = "Owner name",
        [22] = "Horse armor",
    },
    [Bat] = {
        [16] = "Is hanging",
    },
    [Tameable] = {
        [16] = "Tameable flags",
        [17] = "Owner name",
    },
    [Ocelot] = {
        [18] = "Ocelot type",
    },
    [Wolf] = {
        [18] = "Health",
        [19] = "Begging",
        [20] = "Collar color",
    },
    [Pig] = {
        [16] = "Has saddle",
    },
    [Rabbit] = {
        [18] = "Rabbit type",
    },
    [Sheep] = {
        [16] = "Sheep color",
    },
    [Villager] = {
        [16] = "Villager type",
    },
    [Enderman] = {
        [16] = "Carried block",
        [17] = "Carried block data",
        [18] = "Is screaming",
    },
    [Zombie] = {
        [12] = "child zombie",
        [13] = "villager zombie",
        [14] = "converting zombie",
    },
    [ZombiePigman] = {
    },
    [Blaze] = {
        [16] = "Blaze it motherfucker",
    },
    [Spider] = {
        [16] = "Climbing",
    },
    [CaveSpider] = {
    },
    [Creeper] = {
        [16] = "Creeper state",
        [17] = "is powered",
    },
    [Ghast] = {
        [16] = "is attacking",
    },
    [Slime] = {
        [16] = "Size",
    },
    [MagmaCube] = {
    },
    [Skeleton] = {
        [13] = "Skeleton type",
    },
    [Witch] = {
        [21] = "is aggressive",
    },
    [IronGolem] = {
        [16] = "created by player",
    },
    [Wither] = {
        [17] = "Target 1",
        [18] = "Target 2",
        [19] = "Target 3",
        [20] = "Invulnerable time",
    },
    [Boat] = {
        [17] = "Time since hit",
        [18] = "Forward direction",
        [19] = "Damage taken",
    },
    [Minecart] = {
        [17] = "Shaking power",
        [18] = "Shaking direction",
        [19] = "Damage taken/shaking multiplier",
        [20] = "Block id/data",
        [21] = "Block y",
        [22] = "Show block",
    },
    [FurnaceMinecart] = {
        [16] = "Is powered",
    },
    [Item] = {
        [10] = "Item",
    },
    [Arrow] = {
        [16] = "Is critical",
    },
    [Firework] = {
        [8] = "Firework data",
    },
    [ItemFrame] = {
        [8] = "Framed item",
        [9] = "Rotation",
    },
    [EnderCrystal] = {
        [8] = "Health",
    },
};

static const EntityType ENTITY_HIERARCHY[] = {
    [Entity]          = IllegalEntityType,
    [LivingEntity]    = Entity,
    [Ageable]         = LivingEntity,
    [ArmorStand]      = LivingEntity,
    [Human]           = LivingEntity,
    [Horse]           = Ageable,
    [Bat]             = LivingEntity,
    [Tameable]        = Tameable,
    [Ocelot]          = Tameable,
    [Wolf]            = Tameable,
    [Pig]             = Ageable,
    [Rabbit]          = Ageable,
    [Sheep]           = Ageable,
    [Villager]        = Ageable,
    [Enderman]        = LivingEntity,
    [Zombie]          = LivingEntity,
    [ZombiePigman]    = Zombie,
    [Blaze]           = LivingEntity,
    [Spider]          = LivingEntity,
    [CaveSpider]      = Spider,
    [Creeper]         = LivingEntity,
    [Ghast]           = LivingEntity,
    [Slime]           = LivingEntity,
    [MagmaCube]       = Slime,
    [Skeleton]        = LivingEntity,
    [Witch]           = LivingEntity,
    [IronGolem]       = LivingEntity,
    [Wither]          = LivingEntity,
    [Boat]            = Entity,
    [Minecart]        = Entity,
    [FurnaceMinecart] = Minecart,
    [Item]            = Entity,
    [Arrow]           = Entity,
    [Firework]        = Entity,
    [ItemFrame]       = Entity,
    [EnderCrystal]    = Entity,
};

////////////////////////////////////////////////////////////////////////////////
// Entity Metadata

#define META_BYTE    0
#define META_SHORT   1
#define META_INT     2
#define META_FLOAT   3
#define META_STRING  4
#define META_SLOT    5
#define META_COORD   6
#define META_ROT     7

static const char * METATYPES[] = {
    [META_BYTE]       = "byte",
    [META_SHORT]      = "short",
    [META_INT]        = "int",
    [META_FLOAT]      = "float",
    [META_STRING]     = "string",
    [META_SLOT]       = "slot",
    [META_COORD]      = "coord",
    [META_ROT]        = "rot",
};

////////////////////////////////////////////////////////////////////////////////
// ANSI representation of blocks

#define ANSI_CLEAR     "\x1b[0m"
#define ANSI_PLAYER    "\x1b[5;32;44m$\x1b[0m"
#define ANSI_UNKNOWN   "\x1b[45;36m#"
#define ANSI_ILLBLOCK  "\x1b[5;32;44m#\x1b[0m"

static const char * ANSI_BLOCK[256] = {
    // 00
    "\x1b[0m ",                         // Air
    "\x1b[47m ",                        // Stone
    "\x1b[42;33m\xe2\x96\x91",          // Grass
    "\x1b[43;30m\xe2\x96\x93",          // Dirt
    "\x1b[47;30m\xe2\x96\x99",          // Cobblestone
    "\x1b[43;30;22m\xe2\x96\xa4",       // Planks
    "\x1b[40;32m\xf0\x9f\x8c\xb1",      // Sapling
    "\x1b[47;30m\xe2\x96\x93",          // Bedrock
    "\x1b[44;37m-",                     // Flowing Water
    "\x1b[44;37m ",                     // Water
    "\x1b[41;33;22m\xe2\x96\xa4",       // Flowing Lava
    "\x1b[41;33;22m\xe2\x96\x91",       // Lava
    "\x1b[43;37m\xe2\x96\x91",          // Sand
    "\x1b[47;30m\xe2\x96\x92",          // Gravel
    "\x1b[47;33m\xe2\x97\x86",          // Gold Ore
    "\x1b[47;35m\xe2\x97\x86",          // Iron Ore

    // 10
    "\x1b[47;30m\xe2\x97\x86",          // Iron Ore
    "\x1b[43;30m\xe2\x96\xa2",          // Wood
    "\x1b[40;32m\xe2\x96\x92",          // Leaves
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    "\x1b[47;34m\xe2\x97\x86",          // Iron Ore
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    "\x1b[40;32m\xe2\x96\x92",          // Leaves

    // 20
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // 30
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    "\x1b[47;36m\xe2\x97\x86",          // Iron Ore
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    "\x1b[40;33m\xe1\xba\x9b",          // Wheat
    "\x1b[43;30m\xe2\x90\xa5",          // Farmland
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // 40
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    "\x1b[47;31m\xe2\x97\x86",          // Redstone Ore
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // 50
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    "\x1b[40;32m\xe1\xba\x9b",          // Sugar Cane
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    "\x1b[31;40m#",                     // Netherrack
    ANSI_UNKNOWN,
    "\x1b[33;47m#",                     // Glowstone
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // 60
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // 70
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // 80
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    ANSI_UNKNOWN,
    "\x1b[40;32m\xe1\xba\x9b",          // Carrots
    "\x1b[40;32m\xe1\xba\x9b",          // Potatoes
    ANSI_UNKNOWN,

    // 90
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // A0
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // B0
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // C0
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // D0
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // E0
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,

    // F0
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
    ANSI_UNKNOWN,
};
