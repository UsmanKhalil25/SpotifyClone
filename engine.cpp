#include "engine.h"

Engine::Engine() :header(mResolutionX,mResolutionY), footer(mResolutionX, mResolutionY),sidebar(mResolutionX,mResolutionY),center(mResolutionX,mResolutionY),currentState(AppState::Home),playingState(PlayingState::AllSongs),centerName("Home") {
	mWindow.create(sf::VideoMode(mResolutionX, mResolutionY), "Spotify Clone", ( sf::Style::Close));
	mWindow.setVerticalSyncEnabled(true);
	mWindow.setFramerateLimit(FPS);
}

void Engine::mainLoop() {
	sf::Clock clock;
	sf::Time elapsed = sf::Time::Zero;
	while (mWindow.isOpen()) {
		pollEvents();
		elapsed += clock.restart();
		while (elapsed >= FRAME_TIME) {
			elapsed -= FRAME_TIME;
			update();
		}
		render();
	}
}

void Engine::pollEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
		sidebar.handleEvent(event, currentState,playingState,music,centerName);
		footer.handleEvent(event, currentState,playingState,music);
		center.handleEvent(event,currentState,playingState,music,centerName,sidebar);
		header.handleEvent(event, currentState, playingState, music);
	}
}

void Engine::render() {
	mWindow.clear(sf::Color(18, 18, 18));

	footer.draw(mWindow,currentState,playingState,music);
	sidebar.draw(mWindow,currentState,playingState,music);
	center.draw(mWindow,currentState,playingState,music,sidebar);
	header.draw(mWindow,currentState,playingState,music);

	mWindow.display();
}

void Engine::update() {
	if (currentState == AppState::Exit) {
		mWindow.close();
	}
	center.update(currentState,playingState,music,sidebar);
	footer.update(currentState,playingState,music);
	sidebar.update(currentState, playingState, music);
	header.update(currentState, playingState, music);

}

void Engine::run() {
	mainLoop();
}

Engine::~Engine() {}