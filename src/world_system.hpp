#pragma once

// internal
#include "common.hpp"

// stlib
#include <vector>
#include <random>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_mixer.h>

#include "render_system.hpp"

// Container for all our entities and game logic. Individual rendering / update is
// deferred to the relative update() methods
class WorldSystem
{
public:
	WorldSystem();

	// Creates a window
	GLFWwindow* create_window();

	// starts the game
	void init(RenderSystem* renderer);

	// Releases all associated resources
	~WorldSystem();

	// Steps the game ahead by ms milliseconds
	bool step(float elapsed_ms);

	// Check for collisions
	void handle_collisions();

	// Should the game be over ?
	bool is_over()const;

	bool get_is_player_turn();

	void set_is_player_turn(bool val);
private:
	// Input callback functions
	void on_key(int key, int, int action, int mod);
	void on_mouse(int button, int action, int mod);
	void on_mouse_move(vec2 pos);

	// restart level
	void restart_game();

	// spawn entities
	void spawn_game_entities();

	// OpenGL window handle
	GLFWwindow* window;

	// Number of bug eaten by the chicken, displayed in the window title
	unsigned int points;

	// Game state
	RenderSystem* renderer;
	float current_speed;
	float next_eagle_spawn;
	float next_bug_spawn;
	Entity player_chicken;
	Entity background;
	bool is_player_turn = true;
	bool player_right_click = false;

	// music references
	Mix_Music* background_music;
	Mix_Chunk* chicken_dead_sound;
	Mix_Chunk* chicken_eat_sound;

	// C++ random number generator
	std::default_random_engine rng;
	std::uniform_real_distribution<float> uniform_dist; // number between 0..1
};