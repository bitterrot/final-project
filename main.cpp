#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_ROOMS {DUNGEON, LABORATORY, ARMORY, PRISON, LIBRARY, ALTAR_ROOM, MONUMENT_ROOM, SANCTUM, VAULT, GRAVE, TUNNEL, BALLROOM, KITCHEN, HIVE, FACTORY, DEN, MAZE, SPA, CHAMBER, CAVE, HATCHERY, BORDELLO, GARDEN, CRYPT, TOMB, HALL, ARENA, TEMPLE, OBSERVATORY, PIT};
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, REST, YELL};
enum en_NOUNS {TRAP_DOOR, RING, BLADE, GRENADE, MIRROR, NECRONOMICON, STAFF, BAG, ROD, PET, CLAWS, POLE, BOOTS, SWORD, MAP};

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 30;
const int VERBS = 10;
const int NOUNS = 15;

class words
{
  public:
    string word;
    int code;
};

class room
{
  public:
    string description;
    int exits_to_room[DIRS];
};

// Added code 
class noun
{
  public:
    string word;
    string description;
    int code;
    int location;
    bool can_carry;
};

void set_rooms(room *rms)
{
  rms[DUNGEON].description.assign("dungeon entrance");
  rms[DUNGEON].exits_to_room[NORTH] = NONE; 
  rms[DUNGEON].exits_to_room[EAST] = NONE; 
  rms[DUNGEON].exits_to_room[SOUTH] = MAZE;
  rms[DUNGEON].exits_to_room[WEST] = NONE;

  rms[LABORATORY].description.assign("dark laboratory");
  rms[LABORATORY].exits_to_room[NORTH] = NONE;
  rms[LABORATORY].exits_to_room[EAST] = NONE;
  rms[LABORATORY].exits_to_room[SOUTH] = NONE;
  rms[LABORATORY].exits_to_room[WEST] = TUNNEL;

  rms[ARMORY].description.assign("goblin armory");
  rms[ARMORY].exits_to_room[NORTH] = BORDELLO;
  rms[ARMORY].exits_to_room[EAST] = CAVE;
  rms[ARMORY].exits_to_room[SOUTH] = NONE;
  rms[ARMORY].exits_to_room[WEST] = NONE;

  rms[PRISON].description.assign("zombie prison");
  rms[PRISON].exits_to_room[NORTH] = NONE;
  rms[PRISON].exits_to_room[EAST] = ALTAR_ROOM;
  rms[PRISON].exits_to_room[SOUTH] = NONE;
  rms[PRISON].exits_to_room[WEST] = GRAVE;

  rms[LIBRARY].description.assign("haunted library");
  rms[LIBRARY].exits_to_room[NORTH] = NONE;
  rms[LIBRARY].exits_to_room[EAST] = NONE;
  rms[LIBRARY].exits_to_room[SOUTH] = TOMB;
  rms[LIBRARY].exits_to_room[WEST] = MAZE;

  rms[ALTAR_ROOM].description.assign("dark altar room");
  rms[ALTAR_ROOM].exits_to_room[NORTH] = NONE;
  rms[ALTAR_ROOM].exits_to_room[EAST] = NONE;
  rms[ALTAR_ROOM].exits_to_room[SOUTH] = NONE;
  rms[ALTAR_ROOM].exits_to_room[WEST] = PRISON;

  rms[MONUMENT_ROOM].description.assign("monstrous monument room");
  rms[MONUMENT_ROOM].exits_to_room[NORTH] = NONE;
  rms[MONUMENT_ROOM].exits_to_room[EAST] = NONE;
  rms[MONUMENT_ROOM].exits_to_room[SOUTH] = NONE;
  rms[MONUMENT_ROOM].exits_to_room[WEST] = VAULT;

  rms[SANCTUM].description.assign("specter's sanctum");
  rms[SANCTUM].exits_to_room[NORTH] = VAULT;
  rms[SANCTUM].exits_to_room[EAST] = NONE;
  rms[SANCTUM].exits_to_room[SOUTH] = NONE;
  rms[SANCTUM].exits_to_room[WEST] = HIVE;

  rms[VAULT].description.assign("mimic vault");
  rms[VAULT].exits_to_room[NORTH] = NONE;
  rms[VAULT].exits_to_room[EAST] = MONUMENT_ROOM;
  rms[VAULT].exits_to_room[SOUTH] = SANCTUM;
  rms[VAULT].exits_to_room[WEST] = ARENA;

  rms[GRAVE].description.assign("open grave");
  rms[GRAVE].exits_to_room[NORTH] = NONE;
  rms[GRAVE].exits_to_room[EAST] = PRISON;
  rms[GRAVE].exits_to_room[SOUTH] = NONE;
  rms[GRAVE].exits_to_room[WEST] = TOMB;

  rms[TUNNEL].description.assign("centipede tunnel");
  rms[TUNNEL].exits_to_room[NORTH] = NONE;
  rms[TUNNEL].exits_to_room[EAST] = BALLROOM;
  rms[TUNNEL].exits_to_room[SOUTH] = FACTORY;
  rms[TUNNEL].exits_to_room[WEST] = LABORATORY;

  rms[BALLROOM].description.assign("monster's ballroom");
  rms[BALLROOM].exits_to_room[NORTH] = NONE;
  rms[BALLROOM].exits_to_room[EAST] = OBSERVATORY;
  rms[BALLROOM].exits_to_room[SOUTH] = NONE;
  rms[BALLROOM].exits_to_room[WEST] = TUNNEL;

  rms[KITCHEN].description.assign("witch's kitchen");
  rms[KITCHEN].exits_to_room[NORTH] = NONE;
  rms[KITCHEN].exits_to_room[EAST] = TEMPLE;
  rms[KITCHEN].exits_to_room[SOUTH] = NONE;
  rms[KITCHEN].exits_to_room[WEST] = CHAMBER;

  rms[HIVE].description.assign("brainsucker hive");
  rms[HIVE].exits_to_room[NORTH] = NONE;
  rms[HIVE].exits_to_room[EAST] = SANCTUM;
  rms[HIVE].exits_to_room[SOUTH] = NONE;
  rms[HIVE].exits_to_room[WEST] = TEMPLE;

  rms[FACTORY].description.assign("golem factory");
  rms[FACTORY].exits_to_room[NORTH] = TUNNEL;
  rms[FACTORY].exits_to_room[EAST] = CHAMBER;
  rms[FACTORY].exits_to_room[SOUTH] = NONE;
  rms[FACTORY].exits_to_room[WEST] = DEN;

  rms[DEN].description.assign("liger's den");
  rms[DEN].exits_to_room[NORTH] = NONE;
  rms[DEN].exits_to_room[EAST] = FACTORY;
  rms[DEN].exits_to_room[SOUTH] = NONE;
  rms[DEN].exits_to_room[WEST] = NONE;
  
  rms[MAZE].description.assign("minotaur's maze");
  rms[MAZE].exits_to_room[NORTH] = DUNGEON;
  rms[MAZE].exits_to_room[EAST] = LIBRARY;
  rms[MAZE].exits_to_room[SOUTH] = HALL;
  rms[MAZE].exits_to_room[WEST] = HATCHERY;

  rms[SPA].description.assign("succubus spa");
  rms[SPA].exits_to_room[NORTH] = NONE;
  rms[SPA].exits_to_room[EAST] = NONE;
  rms[SPA].exits_to_room[SOUTH] = NONE;
  rms[SPA].exits_to_room[WEST] = CAVE;

  rms[CHAMBER].description.assign("torture chamber");
  rms[CHAMBER].exits_to_room[NORTH] = NONE;
  rms[CHAMBER].exits_to_room[EAST] = KITCHEN;
  rms[CHAMBER].exits_to_room[SOUTH] = NONE;
  rms[CHAMBER].exits_to_room[WEST] = FACTORY;

  rms[CAVE].description.assign("neanderthal cave");
  rms[CAVE].exits_to_room[NORTH] = NONE;
  rms[CAVE].exits_to_room[EAST] = SPA;
  rms[CAVE].exits_to_room[SOUTH] = NONE;
  rms[CAVE].exits_to_room[WEST] = ARMORY;

  rms[HATCHERY].description.assign("dragon hatchery");
  rms[HATCHERY].exits_to_room[NORTH] = NONE;
  rms[HATCHERY].exits_to_room[EAST] = MAZE;
  rms[HATCHERY].exits_to_room[SOUTH] = NONE;
  rms[HATCHERY].exits_to_room[WEST] = GARDEN;

  rms[BORDELLO].description.assign("vampire bordello");
  rms[BORDELLO].exits_to_room[NORTH] = NONE;
  rms[BORDELLO].exits_to_room[EAST] = GARDEN;
  rms[BORDELLO].exits_to_room[SOUTH] = ARMORY;
  rms[BORDELLO].exits_to_room[WEST] = NONE;

  rms[GARDEN].description.assign("fangroot garden");
  rms[GARDEN].exits_to_room[NORTH] = NONE;
  rms[GARDEN].exits_to_room[EAST] = HATCHERY;
  rms[GARDEN].exits_to_room[SOUTH] = NONE;
  rms[GARDEN].exits_to_room[WEST] = BORDELLO;

  rms[CRYPT].description.assign("arcane crypt");
  rms[CRYPT].exits_to_room[NORTH] = TOMB;
  rms[CRYPT].exits_to_room[EAST] = ARENA;
  rms[CRYPT].exits_to_room[SOUTH] = NONE;
  rms[CRYPT].exits_to_room[WEST] = NONE;

  rms[TOMB].description.assign("cursed tomb");
  rms[TOMB].exits_to_room[NORTH] = LIBRARY;
  rms[TOMB].exits_to_room[EAST] = GRAVE;
  rms[TOMB].exits_to_room[SOUTH] = CRYPT;
  rms[TOMB].exits_to_room[WEST] = NONE;

  rms[HALL].description.assign("hall of mirrors");
  rms[HALL].exits_to_room[NORTH] = MAZE;
  rms[HALL].exits_to_room[EAST] = NONE;
  rms[HALL].exits_to_room[SOUTH] = OBSERVATORY;
  rms[HALL].exits_to_room[WEST] = NONE;

  rms[ARENA].description.assign("bloodsoaked arena");
  rms[ARENA].exits_to_room[NORTH] = NONE;
  rms[ARENA].exits_to_room[EAST] = VAULT;
  rms[ARENA].exits_to_room[SOUTH] = NONE;
  rms[ARENA].exits_to_room[WEST] = CRYPT;

  rms[TEMPLE].description.assign("imp temple");
  rms[TEMPLE].exits_to_room[NORTH] = NONE;
  rms[TEMPLE].exits_to_room[EAST] = HIVE;
  rms[TEMPLE].exits_to_room[SOUTH] = NONE;
  rms[TEMPLE].exits_to_room[WEST] = KITCHEN;

  rms[OBSERVATORY].description.assign("spacious observatory");
  rms[OBSERVATORY].exits_to_room[NORTH] = HALL;
  rms[OBSERVATORY].exits_to_room[EAST] = NONE;
  rms[OBSERVATORY].exits_to_room[SOUTH] = NONE;
  rms[OBSERVATORY].exits_to_room[WEST] = BALLROOM;

  rms[PIT].description.assign("bottomless pit");
  rms[PIT].exits_to_room[NORTH] = NONE;
  rms[PIT].exits_to_room[EAST] = NONE;
  rms[PIT].exits_to_room[SOUTH] = NONE;
  rms[PIT].exits_to_room[WEST] = NONE;
}

void set_directions(words *dir)
{
  dir[NORTH].code = NORTH;
  dir[NORTH].word	= "NORTH";
  dir[EAST].code = EAST;
  dir[EAST].word	= "EAST";
  dir[SOUTH].code = SOUTH;
  dir[SOUTH].word	= "SOUTH";
  dir[WEST].code = WEST;
  dir[WEST].word	= "WEST";
}

void set_verbs(words *vbs)
{
  vbs[GET].code = GET;
  vbs[GET].word = "GET";
  vbs[DROP].code = DROP;
  vbs[DROP].word = "DROP";
  vbs[USE].code = USE;
  vbs[USE].word = "USE";
  vbs[OPEN].code = OPEN;
  vbs[OPEN].word = "OPEN";
  vbs[CLOSE].code = CLOSE;
  vbs[CLOSE].word = "CLOSE";
  vbs[EXAMINE].code = EXAMINE;
  vbs[EXAMINE].word = "EXAMINE";
  vbs[INVENTORY].code = INVENTORY;
  vbs[INVENTORY].word = "INVENTORY";
  vbs[LOOK].code = LOOK;
  vbs[LOOK].word = "LOOK";
  vbs[REST].code = REST;
  vbs[REST].word = "REST";
  vbs[YELL].code = YELL;
  vbs[YELL].word = "YELL";
}

void set_nouns(noun *nns)
{
  nns[TRAP_DOOR].word = "DOOR";
  nns[TRAP_DOOR].code = TRAP_DOOR;
  nns[TRAP_DOOR].description = "a closed trap door";
  nns[TRAP_DOOR].can_carry = false;
  nns[TRAP_DOOR].location = ALTAR_ROOM;

  nns[RING].word = "RING";
  nns[RING].code = RING;
  nns[RING].description = "a ring of invisibility";
  nns[RING].can_carry = true;
  nns[RING].location = GRAVE;

  nns[BLADE].word = "BLADE";
  nns[BLADE].code = BLADE;
  nns[BLADE].description = "a vorpal blade";
  nns[BLADE].can_carry = true;
  nns[BLADE].location = ARMORY;

  nns[GRENADE].word = "GRENADE";
  nns[GRENADE].code = GRENADE;
  nns[GRENADE].description = "a holy hand grenade";
  nns[GRENADE].can_carry = true;
  nns[GRENADE].location = LABORATORY;

  nns[MIRROR].word = "MIRROR";
  nns[MIRROR].code = MIRROR;
  nns[MIRROR].description = "a magic mirror";
  nns[MIRROR].can_carry = false;
  nns[MIRROR].location = HALL;
  
  nns[NECRONOMICON].word = "NECRONOMICON";
  nns[NECRONOMICON].code = NECRONOMICON;
  nns[NECRONOMICON].description = "the necronomicon";
  nns[NECRONOMICON].can_carry = true;
  nns[NECRONOMICON].location = LIBRARY;

  nns[STAFF].word = "STAFF";
  nns[STAFF].code = STAFF;
  nns[STAFF].description = "a staff of healing";
  nns[STAFF].can_carry = true;
  nns[STAFF].location = CHAMBER;

  nns[BAG].word = "BAG";
  nns[BAG].code = BAG;
  nns[BAG].description = "a bag of holding";
  nns[BAG].can_carry = true;
  nns[BAG].location = VAULT;

  nns[ROD].word = "ROD";
  nns[ROD].code = ROD;
  nns[ROD].description = "an ice rod";
  nns[ROD].can_carry = true;
  nns[ROD].location = CRYPT;

  nns[PET].word = "PET";
  nns[PET].code = PET;
  nns[PET].description = "a pet monster";
  nns[PET].can_carry = false;
  nns[PET].location = BALLROOM;

  nns[CLAWS].word = "CLAWS";
  nns[CLAWS].code = CLAWS;
  nns[CLAWS].description = "claws of the berserker";
  nns[CLAWS].can_carry = true;
  nns[CLAWS].location = DEN;

  nns[POLE].word = "POLE";
  nns[POLE].code = POLE;
  nns[POLE].description = "a ten foot pole";
  nns[POLE].can_carry = true;
  nns[POLE].location = TUNNEL;

  nns[BOOTS].word = "BOOTS";
  nns[BOOTS].code = BOOTS;
  nns[BOOTS].description = "boots of jumping";
  nns[BOOTS].can_carry = true;
  nns[BOOTS].location = ARENA;

  nns[SWORD].word = "SWORD";
  nns[SWORD].code = SWORD;
  nns[SWORD].description = "an oversized sword";
  nns[SWORD].can_carry = true;
  nns[SWORD].location = KITCHEN;

  nns[MAP].word = "MAP";
  nns[MAP].code = MAP;
  nns[MAP].description = "a map";
  nns[MAP].can_carry = true;
  nns[MAP].location = DUNGEON;

}

void section_command(string Cmd, string &wd1, string &wd2)
{
  string sub_str;
  vector<string> words;
  char search = ' ';
  size_t i, j;

  for(i = 0; i < Cmd.size(); i++)
  {
    if(Cmd.at(i) != search)
    {
      sub_str.insert(sub_str.end(), Cmd.at(i));
    }
    if(i == Cmd.size() - 1)
    {
      words.push_back(sub_str);
      sub_str.clear();
    }
    if(Cmd.at(i) == search)
    {
      words.push_back(sub_str);
      sub_str.clear();
    }
  }

  if (words.size() != 0)
  {
    for(i = words.size() - 1; i > 0; i-- )
    { 
      if(words.at(i) == "")
      {
        words.erase(words.begin() + i);
      }
    }

    for(i = 0; i < words.size(); i++)
    {
      for(j = 0; j < words.at(i).size(); j++)
      {
        if(islower(words.at(i).at(j)))
        {
          words.at(i).at(j) = toupper(words.at(i).at(j));
        }
      }
    }
  }

  if(words.size() == 0)
  {                   
    cout << "No command given" << endl;
  }
  if(words.size() == 1)
  {
    wd1 = words.at(0);
  }
  if(words.size() == 2)
  {
    wd1 = words.at(0);
    wd2 = words.at(1);
  }
  if(words.size() > 2)
  {
    cout << "Command too long. Only type one or two words (direction or verb and noun)" << endl;
  }
}

void look_around(int loc, room *rms, words *dir, /* Added parameter */ noun *nns)
{
  int i;
  cout << "I am in a " << rms[loc].description << "." << endl;

  for(i = 0; i < DIRS; i++)
  {
    if(rms[loc].exits_to_room[i] != NONE)
    {
      cout << "There is an exit " << dir[i].word << " to a " << rms[rms[loc].exits_to_room[i]].description << "." << endl;
    }
  }

  // Added code
  // The look command should check which objects (nouns) are in the current room and report them to the player. 
  for(i = 0; i < NOUNS; i++) 
  {
    if(nns[i].location == loc)
    {
      cout << "I see " << nns[i].description << "." << endl;
    }
  }
}

bool parser(int &loc, string wd1, string wd2, words *dir, words *vbs, room *rms, /* Added parameter */ noun *nns)
{
  // Added code
  static bool door_state = false; // false is a closed door. 
  // ....

  int i;
  for(i = 0; i < DIRS; i++)
  {
    if(wd1 == dir[i].word)
    {
      if(rms[loc].exits_to_room[dir[i].code] != NONE)
      {
        loc = rms[loc].exits_to_room[dir[i].code];
        cout << "I am now in a " << rms[loc].description << "." << endl;
        // Added code. A special case for the ALTAR_ROOM MONUMENT_ROOM door.
        if(loc == MONUMENT_ROOM || loc == ALTAR_ROOM)
        {
          nns[TRAP_DOOR].location = loc;
        }
        // ....
        return true;
      }
      else
      {
        cout << "No exit that way." << endl;
        return true;
      }
    }
  }

  // Added code
  int NOUN_MATCH = NONE;
  // ....
  int VERB_ACTION = NONE;
  for(i = 0; i < VERBS; i++)
  {
    if(wd1 == vbs[i].word)
    {
      VERB_ACTION = vbs[i].code;
      break;
    }
  }

  // Added code
  if(wd2 != "")
  {
    for(i = 0; i < NOUNS; i++)
    {
      if(wd2 == nns[i].word)
      {
        NOUN_MATCH = nns[i].code;
        break;
      }
    }
  }

  if(VERB_ACTION == NONE)
  {
    cout << "No valid command entered." << endl;
    return true;
  }

  if(VERB_ACTION == LOOK)
  {
    look_around(loc, rms, dir, /* Added parameter nns */ nns);
    return true;
  }

  // Added code
  // Actions for usage of VERB OPEN 
  if(VERB_ACTION == OPEN)
  {                
    if(NOUN_MATCH == TRAP_DOOR)
    {
      if(loc == ALTAR_ROOM || loc == MONUMENT_ROOM)
      {
        if(door_state == false)
        {
          door_state = true;
          rms[ALTAR_ROOM].exits_to_room[EAST] = PIT;
          rms[PIT].exits_to_room[WEST] = ALTAR_ROOM;
          nns[TRAP_DOOR].description.clear();
          nns[TRAP_DOOR].description.assign("an open trap door");
          cout << "I have opened the door." << endl;
          return true;
        }
        else if(door_state == true)
        {
          cout << "The door is already open." << endl;
          return true;
        }
      }
      else
      {
        cout << "There is no door to open here." << endl;
        return true;
      }
    }
    else
    {
      cout << "Opening that is not possible." << endl;
      return true;
    }
  }
  return false;
}

int main()
{
  string command;
  string word_1;
  string word_2;

  room rooms[ROOMS];
  set_rooms(rooms);

  words directions[DIRS];
  set_directions(directions);

  words verbs[VERBS];
  set_verbs(verbs);

  noun nouns[NOUNS];
  set_nouns(nouns);
  
  int location = DUNGEON;

  while(word_1 != "QUIT")
  {
    command.clear();
    cout << "what shall I do? ";
    getline(cin, command);

    word_1.clear();
    word_2.clear();

    section_command(command, word_1, word_2);

    if(word_1 != "QUIT")
    { 
      parser(location, word_1, word_2, directions, verbs, rooms, /* Added parameter */ nouns);
    }
  }

  return 0;
}