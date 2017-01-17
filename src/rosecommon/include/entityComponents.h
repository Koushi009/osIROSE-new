
#ifndef _ENTITYCOMPONENTS_H_
# define _ENTITYCOMPONENTS_H_

#include "entityx.hh"

#include "components/socketconnector.h"
#include "components/basicinfo.h"
#include "components/stats.h"
#include "components/advancedinfo.h"
#include "components/graphics.h"
#include "components/charactergraphics.h"
#include "components/characterinfo.h"
#include "components/position.h"
#include "components/destination.h"
#include "components/statuseffects.h"
#include "components/skills.h"
#include "components/hotbar.h"
#include "components/ridingitems.h"
#include "components/bulletitems.h"
#include "components/inventory.h"
#include "components/party.h"

using GameComponents = entityx::Components<SocketConnector, BasicInfo, Stats, AdvancedInfo,
      CharacterInfo, Graphics, CharacterGraphics, Position, StatusEffects,
      Skills, Hotbar, Destination, RidingItems, BulletItems, Inventory, Party>;

using EntityManager = entityx::EntityX<GameComponents, entityx::ColumnStorage<GameComponents>, entityx::FeatureFlags::OBSERVABLE>;
template <typename T>
using Component = EntityManager::Component<T>;
using Entity = EntityManager::Entity;

#include "partybase.h"

uint16_t getId(Entity entity);

std::string &getName(Entity entity);

std::shared_ptr<CMapClient> getClient(Entity entity);

bool isConnected(Entity entity);

#endif /* !_ENTITYCOMPONENTS_H_ */
