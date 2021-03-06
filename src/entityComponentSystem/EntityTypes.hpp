#ifndef ENTITYTYPES_H__
#define ENTITYTYPES_H__

#include <vector>

// An Entity is nothing but an ID. This ID is used to get components from ComponentManagers which
// are assigned to the respective entity. Collections of components which are assigned to the same
// Entity provide the entity's data and behaviors.
typedef unsigned int Entity;
bool EntityComparator(Entity a, Entity b);

extern const Entity NullEntity;

typedef std::vector<Entity> EntityList;
typedef std::vector<Entity>::iterator EntityListIterator;
typedef std::vector<Entity>::const_iterator EntityListConstIterator;
typedef std::vector<Entity>::reverse_iterator EntityListReverseIterator;

void EntityListAppendList(EntityList& list, const EntityList& listToAdd);

void EntityListSort(EntityList& list);
void EntityListSortAndRemoveDuplicates(EntityList& list);

// Remove all entities from suspectList which are already in list
// This is bad. At least the name, possibly also the function itself.
void EntityListRemoveNonUniqueEntitiesInSuspect(const EntityList& list, EntityList& suspectList);
void EntityListRemoveUniqueEntitiesInSuspect(const EntityList& list, EntityList& suspectList);

// Linear search for entity. I'll eventually add a binary search function if it can be assumed that
// the list is sorted
bool EntityListFindEntity(EntityList& list, Entity entity);

// This should probably become an enum at some point.
typedef unsigned int ComponentType;

#endif /* end of include guard: ENTITYTYPES_H__ */
