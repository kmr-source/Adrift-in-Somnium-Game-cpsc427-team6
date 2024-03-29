#pragma once

#include "tiny_ecs_registry.hpp"
#include "common.hpp"

#include <../ext/json/single_include/nlohmann/json.hpp>
#include <iostream>
#include <queue>
#include "room_system.hpp"

const std::string SAVE_DATA_PATH = data_path() + "/saveData.json";

using json = nlohmann::json;

class SaveSystem
{
public:
	void saveGameState(std::queue<Entity> entities, RoomSystem& roomSystem);
	bool saveDataExists();
	void deleteFile();
	json getSaveData();
	std::queue<Entity> getSolidTileInteract(std::queue<Entity> orignalqueue); // puts solid/ collidables obj + tileMAp into the entitylist
	json jsonifyPlayer(Entity player);
	void setGameCompleted();
	bool canSaveContinue();
private:
	json jsonifyEntities(std::queue<Entity> entities);
	json jsonifyEnemy(Entity enemy);
	json jsonifyMotion(Motion m);
	json jsonifyStats(Stats s);
	json jsonifyQueueable(Queueable q);
	json jsonifyInventory(Entity inv);
	json jsonifyEquipment(Equipment e);
	json jsonifyInteractables();
	json jsonifyTiles();
	json jsonifyCollidables();
	json jsonifySign(Entity e);
	json jsonifyStatus(Entity e);
	json jsonifySwitch(Entity e);
	json jsonifyChest(Entity e);
	json jsonifySpritesheet(Spritesheet ss);
	json jsonifyArtifact(Artifact a);
	json jsonifyConsumable(Consumable c);
	json jsonifyAnimationData(AnimationData& a);
	json jsonifyRoomSystem(RoomSystem& r);
	json jsonifyBoss(Boss& b);
	json jsonifyAttackIndicators();
	json jsonifyTraps();
	json jsonifySpawnData();
	//json jsonify
};

extern SaveSystem save_system;