#pragma once
#include "Game.h"
#include "GridClass.h"
#include <vector>




Game::Game(std::unique_ptr<GameMode> mode, int rows, int cols)
	: mode(std::move(mode)), grid(rows, cols, 800.f, 600.f), window(sf::VideoMode(1200, 1080), "SOSGAME") {
	
	width = grid.getWidth();
	float height = grid.getHeight();
	gridSize = rows;

	window.setFramerateLimit(60);
	CenterGameBoardX = window.getSize().x / 2.f - width / 2.f;
	CenterGameBoardY = window.getSize().y / 2.f - height / 2.f;
	
	centerX = window.getSize().x / 2.f - 60;
	squareSize = width / rows;
	initUI();

}



void Game::initUI() {	
	initLabels();
	initUIButtons();
}

void Game::initLabels() {
	//ui labels init
	TitleLable.initLabel(800, 23, "SOS GAME", "Cyan", 60);
	SimpleLabel.initLabel(60, 23, "Simple Game", "White", 55);
	GeneralLabel.initLabel(60, 65, "General Game", "Cyan", 55);
	ThreebyLabel.initLabel(60, 160, "3x3", "Magenta", 35);
	FivebyLabel.initLabel(160, 160, "5x5 ", "Red", 35);
	SevenbyLabel.initLabel(260, 160, "7x7 ", "Yellow", 35);

	//player controls init
	Player1Label.initLabel(23, 200, "Player 1", "White", 30);
	Player2Label.initLabel(123, 200, "Player 2", "White", 30);
	Player1S.initLabel(63, 250, "S", "White", 40);
	Player2S.initLabel(163, 250, "S", "White", 40);
	Player1O.initLabel(63, 320, "O", "White", 40);
	Player2O.initLabel(163, 320, "O", "White", 40);

	HumanLabelP1.initLabel(63, 410, "Human", "White", 25);
	HumanLabelP2.initLabel(199, 410, "Human", "White", 25);
	ComputerLabelP1.initLabel(63, 480, "Computer", "Magenta", 25);
	ComputerLabelP2.initLabel(197, 480, "Computer", "Magenta", 25);

}
void Game::initUIButtons() {
	SimpleGameBtn.initRadioButton(43, 60, 13, 8, "simpleGamebtn");
	GeneralGameBtn.initRadioButton(43, 100, 13, 8, "generalGamebtn");

	ThreeByThree.initRadioButton(43, 160, 11, 8, "threebythree");
	FiveByFive.initRadioButton(143, 160, 11, 8, "fivebyfive");
	SevenBySeven.initRadioButton(243, 160, 11, 8, "sevenbyseven");

	sizebtns.addRadioButton(&ThreeByThree);
	sizebtns.addRadioButton(&FiveByFive);
	sizebtns.addRadioButton(&SevenBySeven);

	S_moveP1.initRadioButton(43, 280, 11, 8, "p1S");
	O_moveP1.initRadioButton(43, 350, 11, 8, "p1O");
	HumanBtnP1.initRadioButton(43, 420, 11, 8, "p1H");
	ComputerBtnP1.initRadioButton(43, 480, 11, 8, "p1C");

	/*Player1BtnGroup.addRadioButton(&HumanBtnP1);
	Player1BtnGroup.addRadioButton(&ComputerBtnP1);*/
	Player1BtnGroup.addRadioButton(&S_moveP1);
	Player1BtnGroup.addRadioButton(&O_moveP1);

	S_moveP2.initRadioButton(143, 280, 11, 8, "p2S");
	O_moveP2.initRadioButton(143, 350, 11, 8, "p2O");
	HumanBtnP2.initRadioButton(183, 420, 11, 8, "p2H");
	ComputerBtnP2.initRadioButton(183, 480, 11, 8, "p2C");

	/*Player2BtnGroup.addRadioButton(&HumanBtnP2);
	Player2BtnGroup.addRadioButton(&ComputerBtnP2);*/
	Player2BtnGroup.addRadioButton(&S_moveP2);
	Player2BtnGroup.addRadioButton(&O_moveP2);
}

void Game::start() {
	std::cout << "Game is Loading...\n" << std::endl;
	if (dynamic_cast<SimpleMode*>(mode.get())) {
		// mode is pointing to an instance of SimpleGame
		std::cout << "The current game mode is SimpleGame." << std::endl;
	}
	else if (dynamic_cast<GeneralMode*>(mode.get())) {
		// mode is pointing to an instance of GeneralGame
		std::cout << "The current game mode is GeneralGame." << std::endl;
	}
	else {
		// mode is of some other type will check for the gamemode select screen 
		std::cout << "The current game mode is unknown." << std::endl;
	}
	mode->Rules();

	//updateGameLogic();
	
	handleEvents();
	render();

	
	
	
}




void Game::RenderMenus(std::string key) {
	window.clear();
	
	SimpleGameBtnend.initRadioButton(300, 300, 20, 16,"simpleGamebtnend");
	GeneralGameBtnend.initRadioButton(600, 300, 20, 16,"generalGamebtnend");

	SimpleLabelend.initLabel(250, 300, "Simple Game", "White", 50);
	GeneralLabelend.initLabel(500, 300, "General Game", "Green", 50);
	userDirection.initLabel(300, 200, "Choose Your Game Mode", "White", 50);
	
	if (key == "main-menu") {
		//do the main menu button select screen
		renderMainMenu();

	}
	else if (key == "simple-end") {
		//end screen for the simple game
		renderEndScreen("simple");
	}	
	else if (key == "general-end") {
		renderEndScreen("general");

	}
}


void Game::updateSimpleUI() {
	GeneralGameBtnend.setState(false);
	GeneralGameBtnend.setInnerColor("Transparent");
	SimpleLabelend.set_labelColor("Green");
	GeneralLabelend.set_labelColor("Cyan");

	GeneralGameBtn.setState(false);
	GeneralGameBtn.setInnerColor("Transparent");
	SimpleLabel.set_labelColor("Green");
	GeneralLabel.set_labelColor("Cyan");

	SimpGame = true;
	GenGame = false;
	Player1_turn = true;
	Player2_turn = false;
	window.clear();
	grid.ResetGrid();
	GameRunning = true;
	MainMenu = false;

	simpleGame.resetGame();


}


void Game::updateGeneralUI() {
	SimpleGameBtnend.setState(false);
	SimpleGameBtnend.setInnerColor("Transparent");
	GeneralLabelend.set_labelColor("Green");
	SimpleLabelend.set_labelColor("Cyan");

	SimpleGameBtn.setState(false);
	SimpleGameBtn.setInnerColor("Transparent");
	GeneralLabel.set_labelColor("Green");
	SimpleLabel.set_labelColor("Cyan");

	SimpGame = false;
	GenGame = true;
	Player1_turn = true;
	Player2_turn = false;
	grid.ResetGrid();
	window.clear();
	GameRunning = true;
	MainMenu = false;
	generalGame.resetGame();

}


void Game::renderMainMenu() {
	std::string userText = "Choose Your Game Mode";
	userDirection.set_labelText(userText);
	TitleLable.draw_Label(window);
	userDirection.draw_Label(window);
	SimpleLabelend.draw_Label(window);
	GeneralLabelend.draw_Label(window);
	SimpleGameBtnend.drawButton(window);
	GeneralGameBtnend.drawButton(window);
	window.display();
	if (SimpleGameBtnend.handleClick(event.mouseButton.x, event.mouseButton.y)) {
		updateSimpleUI();
	}
	else if (GeneralGameBtnend.handleClick(event.mouseButton.x, event.mouseButton.y)) {
		updateGeneralUI();
	}
}



void Game::renderEndScreen(std::string key) {
	Label gameOverG;
	std::string userText = "Press Space to play again!";
	std::string gameOverText;

	if (key == "simple") {
		gameOverText = simpleGame.getEndString();
	}
	else if (key == "general") {
		gameOverText = generalGame.getEndString();
	}

	gameOverG.initLabel(300, 300, gameOverText, "White", 50);
	userDirection.set_labelText(userText);
	gameOverG.draw_Label(window);
	userDirection.draw_Label(window);
	window.display();
	while (window.pollEvent(event)) {

		if (event.type == sf::Event::Closed) {
			window.close();

		}
		if (event.type == sf::Event::Resized) {
			//on resize update the window area / size
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(visibleArea));
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
			std::cout << "Loading Game Select..." << std::endl;
			window.clear();
			GameRunning = false;
			generalEnd = false;
			simpleEnd = false;
			SimpGame = false;
			GenGame = false;
			MainMenu = true;
			if (key == "general") {
				updateGeneralUI();
			}
			if (key == "simple") {
				updateSimpleUI();
			}
			
		}
	}
}

//helper function 
void Game::clearStatus() {
	Player1_turn = true;
	Player2_turn = false;
	grid.ResetGrid();
	window.clear();
}

void Game::handleEvents() {

	float width = grid.getWidth();
	float height = grid.getHeight();
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			//std::cout << "Game is open...\n" << std::endl;
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::Resized) {
				//on resize update the window area / size
			
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));

				////on resize update the center for the game grid
				CenterGameBoardX = event.size.width / 2.f - width / 2.f;
				CenterGameBoardY = event.size.height / 2.f - height / 2.f;
				centerX = event.size.width / 2.f - 80;

				float titleLabelY = 23;
				sf::Vector2f titleLabelPos;
				titleLabelPos.x = centerX;
				titleLabelPos.y = titleLabelY;

				TitleLable.set_LabelPos(titleLabelPos);

				//calculate square size on resize
				squareSize = width / gridSize;
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				handleInput();
			}	
		}
		updateGameLogic();
	}
	window.clear(sf::Color::Black);
	
}

void Game::checkGameEnd(std::string game) {
	if (game == "simple") {
		if (!simpleGame.getGameState()) {
			//the simple game has ended. 
			SimpGame = false;
			SimpleGameBtn.setState(false);
			GameRunning = false;
			simpleEnd = true;
		}
	}
	
	if (game == "general") {
		if (!generalGame.getGameState()) {
			//the general game has ended. 
			GenGame = false;
			GeneralGameBtn.setState(false);
			GameRunning = false;
			generalEnd = true;
			
		}
	}
}
void Game::validateMove(int row, int col, std::string gameType, std::string key , int currPlayer) {
	if (grid.getCellState(row, col) == 0) {
		if (gameType == "simple") {
			simpleGame.makeMove(grid, row, col, key, currPlayer, gridSize);

			checkGameEnd("simple");
		}
		else if (gameType == "general") {
			generalGame.makeMove(grid, row, col, key, currPlayer, gridSize);

			checkGameEnd("general");
		}
	}

	if (Player1_turn) {
		Player1_turn = false;
		Player2_turn = true;
	}
	else {
		Player2_turn = false;
		Player1_turn = true;
	}
}


void Game::playerOneMoves(int row, int col, std::string gameType) {
	std::string key = Player1BtnGroup.findSelection();
	if (key == "p1S") {
		key = "s";
	}
	else if (key == "p1O") {
		key = "o";
	}
	
	if (!Player1IsHuman) {
		std::cout << "player option chosen: bot" << std::endl;
		std::shared_ptr<GameMode> gameMode = std::make_unique<SimpleMode>();
		Bot Player1Bot(gameMode);
		if (gameType == "simple") {
			Player1Bot.botMakeMove(grid, 1, gridSize);
			if (Player1_turn) {
				Player1_turn = false;
				Player2_turn = true;
			}
			else {
				Player2_turn = false;
				Player1_turn = true;
			}
		}
		else if (gameType == "general") {
			gameMode = std::make_unique<GeneralMode>();
			Player1Bot.setGameMode(gameMode);
			Player1Bot.botMakeMove(grid, 1, gridSize);
			if (Player1_turn) {
				Player1_turn = false;
				Player2_turn = true;
			}
			else {
				Player2_turn = false;
				Player1_turn = true;
			}
		}
		
	}
	else {
		validateMove(row, col, gameType, key, 1);
	}
	
	

	
}

void Game::playerTwoMoves(int row, int col, std::string gameType) {
	std::string key = Player2BtnGroup.findSelection();
	if (key == "p2S") {
		key = "s";
	}
	else if (key == "p2O") {
		key = "o";
	}
	if (!Player2IsHuman) {
		std::shared_ptr<GameMode> gameMode = std::make_unique<SimpleMode>();
		Bot Player2Bot(gameMode);
		if (gameType == "simple") {
			Player2Bot.botMakeMove(grid, 2, gridSize);
			if (Player1_turn) {
				Player1_turn = false;
				Player2_turn = true;
			}
			else {
				Player2_turn = false;
				Player1_turn = true;
			}
		}
		else if (gameType == "general") {
			gameMode = std::make_unique<GeneralMode>();
			Player2Bot.setGameMode(gameMode);
			Player2Bot.botMakeMove(grid, 2, gridSize);
			if (Player1_turn) {
				Player1_turn = false;
				Player2_turn = true;
			}
			else {
				Player2_turn = false;
				Player1_turn = true;
			}
		}
	
		
	}
	else {
		validateMove(row, col, gameType, key, 2);
	}
	

}

void Game::makingGameMoves(int row, int col,std::string gameType) {
	std::string key;
	
	if (Player1_turn) {
		playerOneMoves(row, col, gameType);
		std::cout << "Current Player 1 turn" << std::endl;
		

	}
	else if (Player2_turn) {
		playerTwoMoves(row, col, gameType);
		std::cout << "Current Player 2 turn" << std::endl;
		 

	}
	
	
}

//when  mouse input is detected , look for updates in the game buttons (simple and General) 
void Game::updateGameButtons(sf::Vector2i mousePos) {
	if (SimpleGameBtn.handleClick(mousePos.x, mousePos.y)) {
		// Ensure only one button is active at a time
		updateSimpleUI();

	}
	else if (GeneralGameBtn.handleClick(mousePos.x, mousePos.y)) {
		updateGeneralUI();
	}
	//update text colors 
	if (!SimpleGameBtn.getState()) {
		SimpleLabel.set_labelColor("White");

	}
	if (!GeneralGameBtn.getState()) {
		GeneralLabel.set_labelColor("Cyan");

	}
}


//when  mouse input is detected , look for updates in the game size buttons
void Game::updateSizeButtons(sf::Vector2i mousePos) {

	// Ensure only one button is active at a time
	if (ThreeByThree.handleClick(mousePos.x, mousePos.y)) {
		sizebtns.updateGroup("threebythree");
		ThreebyLabel.set_labelColor("White");
		gridSize = 3.f;
		clearStatus();
		squareSize = width / gridSize;
	}
	else if (FiveByFive.handleClick(mousePos.x, mousePos.y)) {
		sizebtns.updateGroup("fivebyfive");
		FivebyLabel.set_labelColor("White");
		gridSize = 5.f;
		clearStatus();

		squareSize = width / gridSize;

	}
	else if (SevenBySeven.handleClick(mousePos.x, mousePos.y)) {
		sizebtns.updateGroup("sevenbyseven");
		SevenbyLabel.set_labelColor("White");
		gridSize = 7.f;
		clearStatus();
		squareSize = width / gridSize;
	}
	if (!ThreeByThree.getState()) {
		ThreebyLabel.set_labelColor("Magenta");
	}
	if (!FiveByFive.getState()) {
		FivebyLabel.set_labelColor("Red");
	}
	if (!SevenBySeven.getState()) {
		SevenbyLabel.set_labelColor("Yellow");
	}
}


//when  mouse input is detected , look for updates in the Player move buttons
void Game::updatePlayerMoveUI(sf::Vector2i mousePos) {
	//Making a move 
	if (S_moveP1.handleClick(mousePos.x, mousePos.y)) {
		O_moveP1.setState(false);
		O_moveP1.setInnerColor("Transparent");
	}
	else if (O_moveP1.handleClick(mousePos.x, mousePos.y)) {
		S_moveP1.setState(false);
		S_moveP1.setInnerColor("Transparent");
	}
	else if (S_moveP2.handleClick(mousePos.x, mousePos.y)) {
		O_moveP2.setState(false);
		O_moveP2.setInnerColor("Transparent");
	}
	else if (O_moveP2.handleClick(mousePos.x, mousePos.y)) {
		S_moveP2.setState(false);
		S_moveP2.setInnerColor("Transparent");
	}

	if (HumanBtnP1.handleClick(mousePos.x, mousePos.y)) {
		ComputerBtnP1.setState(false);
		ComputerBtnP1.setInnerColor("Transparent");
		Player1IsHuman = true;

	}
	else if (HumanBtnP2.handleClick(mousePos.x, mousePos.y)) {
		ComputerBtnP2.setState(false);
		ComputerBtnP2.setInnerColor("Transparent");
		Player2IsHuman = true;

	}
	else if (ComputerBtnP1.handleClick(mousePos.x, mousePos.y)) {
		HumanBtnP1.setState(false);
		HumanBtnP1.setInnerColor("Transparent");
		Player1IsHuman = false;


	}
	else if (ComputerBtnP2.handleClick(mousePos.x, mousePos.y)){
		HumanBtnP2.setState(false);
		HumanBtnP2.setInnerColor("Transparent");
		Player2IsHuman = false;

	}
}

void Game::updateUIOnMouseInput(sf::Vector2i mousePos) {
	updateGameButtons(mousePos);
	updateSizeButtons(mousePos);
	updatePlayerMoveUI(mousePos);
}


// handle mouse interaction with the game
void Game::handleInput() { 
	//std::cout << "Handling Input...\n" << std::endl;
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		updateUIOnMouseInput(mousePos);
		

		if (mousePos.x >= CenterGameBoardX && mousePos.x <= CenterGameBoardX + gridSize * squareSize && mousePos.y >= CenterGameBoardY && mousePos.y <= CenterGameBoardY + gridSize * squareSize) {
			int col = (mousePos.x - CenterGameBoardX) / squareSize;
			int row = (mousePos.y - CenterGameBoardY) / squareSize;
			std::string key = "";
			if (row >= 0 && row < gridSize && col >= 0 && col < gridSize) {
				std::cout << "Mouse is at: row = " << row << ", col = " << col << std::endl;
				if (SimpGame == true ) {
					//Simple game is mode
					makingGameMoves(row, col, "simple");
				}
				else if (GenGame == true){
					//else General Game is mode
					makingGameMoves(row, col, "general");
				}
				else {
					std::cout << "GAME MODE ERR OCCURED" << std::endl;
				}
				updateGameLogic();
			}
		}
	}
}
	



//update the game logic
void Game::updateGameLogic() {
	if (!(GameRunning) and MainMenu == true) {
		//run  main menu screen 
		std::string main = "main-menu";
		RenderMenus(main);
	}
	else if (!(GameRunning) and simpleEnd == true) {
		std::string ending = "simple-end";
		RenderMenus(ending);
	}
	else if (!(GameRunning) and generalEnd == true) {
		std::string ending = "general-end";
		RenderMenus(ending);
	}
	else {
		render();
	}
}


//render current game sate
void Game::render() {
	window.clear(sf::Color::Black);
	//std::cout << "Game is Rendering...\n" << std::endl;
	std::vector<int> dimensions = grid.getDimensions();
	
	float width = dimensions[1];
	
	grid.drawCells(window, squareSize, gridSize, CenterGameBoardX, CenterGameBoardY, width);
	Player1Label.draw_Label(window);
	Player2Label.draw_Label(window);
	Player1S.draw_Label(window);
	Player2S.draw_Label(window);
	Player1O.draw_Label(window);
	Player2O.draw_Label(window);
	HumanLabelP1.draw_Label(window);
	HumanLabelP2.draw_Label(window);
	ComputerLabelP1.draw_Label(window);
	ComputerLabelP2.draw_Label(window);
	TitleLable.draw_Label(window);
	SimpleLabel.draw_Label(window);
	GeneralLabel.draw_Label(window);
	ThreebyLabel.draw_Label(window);
	FivebyLabel.draw_Label(window);
	SevenbyLabel.draw_Label(window);

	SimpleGameBtn.drawButton(window);
	GeneralGameBtn.drawButton(window);
	ThreeByThree.drawButton(window);
	FiveByFive.drawButton(window);
	SevenBySeven.drawButton(window);
	S_moveP1.drawButton(window);
	O_moveP1.drawButton(window);
	S_moveP2.drawButton(window);
	O_moveP2.drawButton(window);
	HumanBtnP1.drawButton(window);
	HumanBtnP2.drawButton(window);
	ComputerBtnP1.drawButton(window);
	ComputerBtnP2.drawButton(window);
	
	
	window.display();

}
