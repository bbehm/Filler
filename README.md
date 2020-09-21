# Filler

Filler is a project for my Hive Helsinki studies. It is about creating an algorithm that competes against others in a simple game.

__Usage:__
```
./filler_vm -f <map> -p1 <player1> -p2 <player2>
```

__For example__
```
git clone https://github.com/bbehm/Filler.git | cd Filler
./filler_vm -f maps/map01 -p1 players/abanlin.filler -p2 ./bbehm.filler
```

My own player can be found as `bbehm.filler` at the root of the repo and opponent players can be found in the `players` folder - they can however be a big buggy.

Three sample maps can be found in the `maps` folder.


![filler_gif](gif_2.gif)

Visualizer used in gif made by [avocadohooman](https://github.com/avocadohooman)!

## The game

Filler is a game to be played by two players. Each player in turn get a piece of a random shape to place on the __Filler board__, for each placed piece the players collect points. The piece you place has to fit inside the board completely and has to be placed __exactly one square on top of your own previously placed piece__. The game ends when neither player can place their given piece.

## My solution

My Filler program is using a __heatmap__ to evaluate where to place the pieces. The heatmap gives a score for how close the enemy pieces are and we then choose the 'legal' place that is closet to the enemy to try to prevent them from being able to place pieces.
