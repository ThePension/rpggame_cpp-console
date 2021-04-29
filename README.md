# CPP_FilRouge_ISCD_Aubert

## Control
**You spawn in a room. Your hero is represented with a red X**

![alt text](Docs/Images/Spawn.PNG)

By pressing the `h` key, you open the key's help 
- You can move your hero with `wasd` keys
- You can show your hero's stats by pressing the `$` key
- You can show your hero's inventory by pressing the `i` key
- You can interact with objects in the room by pressing the `f` key
- You can exit the game by pressing the `q` key

![alt text](Docs/Images/KeyHelp.PNG)

## Chest
In the room, **C** character represents chest.
If you go next to a chest and interact with it by pressing the `f` key, its content will be displayed on the right. The highlighted item is currently selected.

![alt text](Docs/Images/ChestContent.PNG)

### Move in inventory

With the `w` and `s` keys, you can change the selected item.

![alt text](Docs/Images/ChestInventoryChangeSelectedItem.PNG)

### Take item

Then, by pressing the `f` key, if you have enough places in your inventory, the selectionned item will be added into your inventory.

![alt text](Docs/Images/AddingItemIntoYourInventory.PNG)

### Take all the items

Or, by pressing simultaneously the `CTRL` + `f` keys, if you have enough places in your inventory, all the items will be added into your inventory.

![alt text](Docs/Images/ChestEmpty.PNG)

### Quit chest inventory

You can exit the chest inventory by pressing the `ESCAPE` or `TAB` key.

## Inventory
The `TAB` key opens
In your inventory (10 items max), the same movement system as for the chest inventory is used.

![alt text](Docs/Images/Inventory.PNG)

### Interaction with items

By pressing `f`, you will interact with the selected item :
- Potion : You will drink the potion, and your HPs will increase
- Weapon : The weapon is then the current weapon (the weapon held by the hero).

### Quit inventory

You can exit your inventory by pressing the `TAB` key.

