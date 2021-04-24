# CPP_FilRouge_ISCD_Aubert

## Control
**You spawn in a room. Your hero is represented with a red X**

By pressing the `h` key, you open the key's help 
- You can move your hero with `wasd` keys
- You can show your hero's stats by pressing the `$` key
- You can show your hero's inventory by pressing the `i` key
- You can interact with objects in the room by pressing the `f` key
- You can exit the game by pressing the `q` key

## Chest
In the room, **C** character represents chest.
If the go next to a chest, its content is displayed on the right
By pressing the `f` key next to a chest, if you have enough places in your inventory, the chest content is added into your inventory.

## Inventory
In your inventory (10 items max), a number is displayed next to every item.

By pressing one of these number while your inventory is open, you will interact with it :
- Potion : You will drink the potion, and your HPs will increase
- Weapon : Not implemented yet

If you press another key that `i` or a number (between 0 and the last item's number in your inventory), the inventory will close.