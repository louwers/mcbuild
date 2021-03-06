/*
 Authors:
 Copyright 2012-2016 by Eduard Broese <ed.broese@gmx.de>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version
 2 of the License, or (at your option) any later version.
*/

/*
  entity : entities and entity metadata handling
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LH_DECLARE_SHORT_NAMES 1
#include <lh_buffers.h>
#include <lh_bytes.h>

#include "entity.h"

// Entities

const char * METANAME[][32] = {
    [Entity] = {
        [0]  = "Flags",
        [1]  = "Air",
        [2]  = "Custom name",
        [3]  = "Name visible",
        [4]  = "Is silent",
    },
    [Potion] = {
        [5]  = "Slot",
    },
    [FallingBlock] = {
        [5]  = "Position",
    },
    [AreaEffectCloud] = {
        [5]  = "Radius",
        [6]  = "Color",
        [7]  = "Single point",
        [8]  = "Particle ID",
    },
    [FishingFloat] = {
        [5]  = "Hooked entity",
    },
    [Arrow] = {
        [5]  = "Is critical",
    },
    [TippedArrow] = {
        [6]  = "Color",
    },
    [Boat] = {
        [5]  = "Time since hit",
        [6]  = "Forward direction",
        [7]  = "Damage taken",
        [8]  = "Type",
        [9]  = "Paddle A",
        [10] = "Paddle B",
    },
    [EnderCrystal] = {
        [5]  = "Beam target",
        [6]  = "Show bottom",
    },
    [Fireball] = {
    },
    [WitherSkull] = {
        [5]  = "Invulnerable",
    },
    [Fireworks] = {
        [5] = "Firework info",
    },
    [Hanging] = {
    },
    [ItemFrame] = {
        [5] = "Item",
        [6] = "Rotation",
    },
    [Item] = {
        [5] = "Item",
    },
    [Living] = {
        [5]  = "Active hand",
        [6]  = "Health",
        [7]  = "Potion effect color",
        [8]  = "Potion effect ambient",
        [9]  = "Number of arrows",
    },
    [Player] = {
        [10] = "Additional hearts",
        [11] = "Score",
        [12] = "Skin flags",
        [13] = "Main hand",
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
    [Insentinent] = {
        [10] = "Insentinent flags",
    },
    [Ambient] = {
    },
    [Bat] = {
        [11] = "Is hanging",
    },
    [Creature] = {
    },
    [Ageable] = {
        [11] = "Is baby",
    },
    [Animal] = {
    },
    [Horse] = {
        [12] = "Horse flags",
        [13] = "Horse type",
        [14] = "Horse color",
        [15] = "Owner UUID",
        [16] = "Horse armor",
    },
    [Pig] = {
        [12] = "Has saddle",
    },
    [Rabbit] = {
        [12] = "Rabbit type",
    },
    [Sheep] = {
        [12] = "Sheep color",
    },
    [TameableAnimal] = {
        [12] = "Tameable flags",
        [13] = "Owner UUID",
    },
    [Ocelot] = {
        [14] = "Ocelot type",
    },
    [Wolf] = {
        [14] = "Damage",
        [15] = "Begging",
        [16] = "Collar color",
    },
    [Villager] = {
        [12] = "Profession",
    },
    [Golem] = {
    },
    [IronGolem] = {
        [11] = "created by player",
    },
    [Snowman] = {
        [10] = "Flags",
    },
    [Shulker] = {
        [11] = "Direction",
        [12] = "Attachment position",
        [13] = "Shield height",
    },
    [Monster] = {
    },
    [Blaze] = {
        [11] = "On fire",
    },
    [Creeper] = {
        [11] = "Creeper state",
        [12] = "Charged",
        [13] = "Ignited",
    },
    [Guardian] = {
        [11] = "Flags",
        [12] = "Target EID",
    },
    [Skeleton] = {
        [11] = "Skeleton type",
        [12] = "Targeting",
    },
    [Spider] = {
        [11] = "Climbing",
    },
    [Witch] = {
        [11] = "Aggressive",
    },
    [Wither] = {
        [11] = "Target 1",
        [12] = "Target 2",
        [13] = "Target 3",
        [14] = "Invulnerable time",
    },
    [Zombie] = {
        [11] = "Baby zombie",
        [12] = "Villager zombie",
        [13] = "Converting zombie",
        [14] = "Hands up",
    },
    [Enderman] = {
        [11] = "Carried block",
        [12] = "Screaming",
    },
    [Enderdragon] = {
        [11] = "Phase",
    },
    [Flying] = {
    },
    [Ghast] = {
        [11] = "Attacking",
    },
    [Slime] = {
        [11] = "Size",
    },
    [Minecart] = {
        [5]  = "Shaking power",
        [6]  = "Shaking direction",
        [7]  = "Shaking multiplier",
        [8]  = "Block id/data",
        [9]  = "Block y",
        [10] = "Show block",
    },
    [MinecartFurnace] = {
        [11] = "Powered",
    },
};

const EntityType ENTITY_HIERARCHY[] = {
    //// Superclasses
    [Entity]            = IllegalEntityType,
    [Potion]            = Entity,
    [FallingBlock]      = Entity,
    [AreaEffectCloud]   = Entity,
    [FishingFloat]      = Entity,
    [Arrow]             = Entity,
    [TippedArrow]       = Arrow,
    [Boat]              = Entity,
    [EnderCrystal]      = Entity,
    [Fireball]          = Entity,
    [WitherSkull]       = Fireball,
    [Fireworks]         = Entity,
    [Hanging]           = Entity,
    [ItemFrame]         = Hanging,
    [Item]              = Entity,
    [Living]            = Entity,
    [Player]            = Living,
    [ArmorStand]        = Living,
    [Insentinent]       = Living,
    [Ambient]           = Insentinent,
    [Bat]               = Ambient,
    [Creature]          = Insentinent,
    [Ageable]           = Creature,
    [Animal]            = Ageable,
    [Horse]             = Animal,
    [Pig]               = Animal,
    [Rabbit]            = Animal,
    [Sheep]             = Animal,
    [TameableAnimal]    = Animal,
    [Ocelot]            = TameableAnimal,
    [Wolf]              = TameableAnimal,
    [Villager]          = Creature,
    [Golem]             = Creature,
    [IronGolem]         = Golem,
    [Snowman]           = Golem,
    [Shulker]           = Golem,
    [Monster]           = Creature,
    [Blaze]             = Monster,
    [Creeper]           = Monster,
    [Guardian]          = Monster,
    [Skeleton]          = Monster,
    [Spider]            = Monster,
    [CaveSpider]        = Spider,
    [Witch]             = Monster,
    [Wither]            = Monster,
    [Zombie]            = Monster,
    [ZombiePigman]      = Zombie,
    [Enderman]          = Monster,
    [Enderdragon]       = Insentinent,
    [Flying]            = Insentinent,
    [Ghast]             = Flying,
    [Slime]             = Insentinent,
    [MagmaCube]         = Slime,
    [Minecart]          = Entity,
    [MinecartCommandBlock] = Minecart,
    [MinecartFurnace]   = Minecart,
    [ActivatedTNT]      = Entity,
};

#define ENUMNAME(name) [name] = #name

const char * ENTITY_NAMES[MaxEntityType] = {
    ENUMNAME(Creeper),
    ENUMNAME(Skeleton),
    ENUMNAME(Spider),
    ENUMNAME(GiantZombie),
    ENUMNAME(Zombie),
    ENUMNAME(Slime),
    ENUMNAME(Ghast),
    ENUMNAME(ZombiePigman),
    ENUMNAME(Enderman),
    ENUMNAME(CaveSpider),
    ENUMNAME(Silverfish),
    ENUMNAME(Blaze),
    ENUMNAME(MagmaCube),
    ENUMNAME(Enderdragon),
    ENUMNAME(Wither),
    ENUMNAME(Bat),
    ENUMNAME(Witch),
    ENUMNAME(Endermite),
    ENUMNAME(Guardian),
    ENUMNAME(Shulker),

    ENUMNAME(Pig),
    ENUMNAME(Sheep),
    ENUMNAME(Cow),
    ENUMNAME(Chicken),
    ENUMNAME(Squid),
    ENUMNAME(Wolf),
    ENUMNAME(Mooshroom),
    ENUMNAME(Snowman),
    ENUMNAME(Ocelot),
    ENUMNAME(IronGolem),
    ENUMNAME(Horse),
    ENUMNAME(Rabbit),
    ENUMNAME(Villager),
};

const char * get_entity_name(char *buf, EntityType type) {
    if (type < 0 || type >= MaxEntityType ) {
        sprintf(buf, "%s", "IllegalEntityType");
    }
    else if ( ENTITY_NAMES[type] ) {
        sprintf(buf, "%s", ENTITY_NAMES[type]);
    }
    else {
        sprintf(buf, "%s", "UnknownEntity");
    }
    return buf;
}

////////////////////////////////////////////////////////////////////////////////
// Entity Metadata

const char * METATYPES[] = {
    [META_BYTE]     = "byte",
    [META_VARINT]   = "varint",
    [META_FLOAT]    = "float",
    [META_STRING]   = "string",
    [META_CHAT]     = "chat",
    [META_SLOT]     = "slot",
    [META_BOOL]     = "bool",
    [META_VEC3]     = "vector3f",
    [META_POS]      = "position",
    [META_OPTPOS]   = "optional_position",
    [META_DIR]      = "direction",
    [META_OPTUUID]  = "optional_uuid",
    [META_BID]      = "block_id",
    [META_NONE]     = "-"
};

metadata * clone_metadata(metadata *meta) {
    if (!meta) return NULL;
    lh_create_num(metadata, newmeta, 32);
    memmove(newmeta, meta, 32*sizeof(metadata));
    int i;
    for(i=0; i<32; i++)
        if (newmeta[i].type == META_SLOT)
            clone_slot(&meta[i].slot, &newmeta[i].slot);
    return newmeta;
}

void free_metadata(metadata *meta) {
    if (!meta) return;
    int i;
    for(i=0; i<32; i++)
        if (meta[i].type == META_SLOT)
            clear_slot(&meta[i].slot);
    free(meta);
}

uint8_t * read_metadata(uint8_t *p, metadata **meta) {
    assert(meta);
    assert(!*meta);
    ssize_t mc = 0;

    // allocate a whole set of 32 values
    lh_alloc_num(*meta, 32);
    metadata *m = *meta;

    int i;
    int bool;

    // mark all entries as not present - we use the same 0xff value
    // that Mojang uses as terminator
    for(i=0; i<32; i++) m[i].type = META_NONE;

    while (1) {
        uint8_t key = read_char(p);
        if (key == 0xff) break; // terminator
        assert(key < 32);

        metadata *mm = &m[key];
        mm->key = key;
        mm->type = read_char(p);

        switch (mm->type) {
            case META_BYTE:     mm->b = read_char(p);    break;
            case META_VARINT:   mm->i = read_varint(p);  break;
            case META_FLOAT:    mm->f = read_float(p);   break;
            case META_STRING:   p = read_string(p,mm->str); break;
            case META_CHAT:     p = read_string(p,mm->chat); break; //VERIFY
            case META_SLOT:     p = read_slot(p,&mm->slot); break;
            case META_BOOL:     mm->bool = read_char(p);  break; //VERIFY
            case META_VEC3:     mm->fx=read_float(p);
                                mm->fy=read_float(p);
                                mm->fz=read_float(p); break;
            case META_POS:      mm->pos.p = read_long(p); break;
            case META_OPTPOS:   bool = read_char(p); //VERIFY
                                if (bool) {
                                    mm->pos.p = read_long(p);
                                }
                                else {
                                    mm->pos.p = (uint64_t)-1;
                                }
                                break;
            case META_DIR:      mm->dir = read_varint(p);  break;
            case META_OPTUUID:  bool = read_char(p); //VERIFY
                                if (bool) {
                                    memmove(mm->uuid,p,sizeof(uuid_t));
                                    p+=sizeof(uuid_t);
                                }
                                break;
            case META_BID:      mm->block = read_char(p); break; // note- block ID only, no meta
        }
    }

    return p;
}

void dump_metadata(metadata *meta, EntityType et) {
    if (!meta) return;

    int i;
    for (i=0; i<32; i++) {
        metadata *mm = meta+i;
        if (mm->type==META_NONE) continue;

        printf("\n    ");

        const char * name = NULL;
        EntityType ett = et;
        while ((!name) && (ett!=IllegalEntityType)) {
            name = METANAME[ett][mm->key];
            ett = ENTITY_HIERARCHY[ett];
        }

        printf("%2d %-24s [%-6s] = ", mm->key, name?name:"Unknown",METATYPES[mm->type]);
        switch (mm->type) {
            case META_BYTE:     printf("%d",  mm->b);   break;
            case META_VARINT:   printf("%d",  mm->i);   break;
            case META_FLOAT:    printf("%.1f",mm->f);   break;
            case META_STRING:
            case META_CHAT:     printf("\"%s\"", mm->str); break;
            case META_SLOT:     dump_slot(&mm->slot); break;
            case META_BOOL:     printf("%s", mm->bool?"true":"false"); break; //VERIFY
            case META_VEC3:     printf("%.1f,%.1f,%.1f", mm->fx, mm->fy, mm->fz); break;
            case META_POS:
            case META_OPTPOS:   printf("%d,%d,%d", mm->pos.x, mm->pos.y, mm->pos.z); break;
            case META_DIR:      printf("%d",mm->dir);  break;
            case META_OPTUUID:  hexprint(mm->uuid, sizeof(uuid_t));
            case META_BID:      printf("%2x (%d)", mm->block, mm->block); //TODO: print material name
            default:            printf("<unknown type>"); break;
        }
    }
}

