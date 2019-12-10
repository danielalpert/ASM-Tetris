.data

Point STRUCT
	;a point with coordinates x, y
	x DWORD ?
	y DWORD ?
Point ends

Tetromino STRUCT
	;a tetromino of type (kind), position (pos), and orientation (rot)
	kind DWORD ? ;kind includes a number representing a type of tetromino:
	;1-O 2-I 3-T 4-L 5-J 6-S 7-Z
	pos Point<>
	rot DWORD 1 ;rot contains a number representing an orientation:
	;1-north 2-east 3-south 4-west
Tetromino ends

Row STRUCT
	;a row including an array of 10 blocks
	blocks DWORD 10 DUP(0) ;each block contains number representing a type of mino:
	;0-empty 1-yellow 2-blue 3-pink 4-orange 5-purple 6-green 7-red 8-surface (not drawn, just for collision)
Row ends

Bag STRUCT
	;a bag containing a random order of the 7 tetrominos (tetrs), the current tetromino in the bag (curr)
	;and a pointer to the next bag's location in the RAM (nextBag)
	tetrs DWORD 7 DUP(?) ;each tetr contains a number representing type of tetromino
	curr DWORD 0
	nextBag DWORD ?
Bag ends

redMinoLoc byte "C:\Users\Daniel\source\repos\Final\Final\Minos\Red.bmp",0
greenMinoLoc byte "C:\Users\Daniel\source\repos\Final\Final\Minos\Green.bmp",0
blueMinoLoc byte "C:\Users\Daniel\source\repos\Final\Final\Minos\Blue.bmp",0
yellowMinoLoc byte "C:\Users\Daniel\source\repos\Final\Final\Minos\Yellow.bmp",0
pinkMinoLoc byte "C:\Users\Daniel\source\repos\Final\Final\Minos\Pink.bmp",0
orangeMinoLoc byte "C:\Users\Daniel\source\repos\Final\Final\Minos\Orange.bmp",0
purpleMinoLoc byte "C:\Users\Daniel\source\repos\Final\Final\Minos\Purple.bmp",0

redLineLoc byte "C:\Users\Daniel\source\repos\Final\Final\Images\red_line.bmp",0
gridLineHorLoc byte "C:\Users\Daniel\source\repos\Final\Final\Images\grid_line_horizontal.bmp",0
gridLineVerLoc byte "C:\Users\Daniel\source\repos\Final\Final\Images\grid_line_vertical.bmp",0
switchLoc byte "C:\Users\Daniel\source\repos\Final\Final\Images\switch.bmp",0

korobeinikiLoc byte "C:\Users\Daniel\source\repos\Final\Final\Korobeiniki.wav",0
lockLoc byte "C:\Users\Daniel\source\repos\Final\Final\Sounds\Lock.wav",0
clearLoc byte "C:\Users\Daniel\source\repos\Final\Final\Sounds\LineClear.wav",0
moveLoc byte "C:\Users\Daniel\source\repos\Final\Final\Sounds\Move.wav",0
rotLoc byte "C:\Users\Daniel\source\repos\Final\Final\Sounds\Rotate.wav",0
gameOverLoc byte "C:\Users\Daniel\source\repos\Final\Final\Sounds\GameOver.wav",0

redLine Img<>
gridLineHor Img<>
gridLineVer Img<>
switchi Img<>

minos Img 7 DUP(<>)
matrix Row 22 DUP(<>)
tetr Tetromino<>
bag1 Bag<>
bag2 Bag<>
currentBag Bag<>

gameFlowThrId DWORD ?
keyHandThrId DWORD ?
randomcntThrId DWORD ?
bgMusicThrId DWORD ?

fallTime DWORD ?
gameOver DWORD ?

temp DWORD ?

falltimedec DWORD ?