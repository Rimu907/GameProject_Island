using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class Inventory : MonoBehaviour
{

    public event EventHandler<InventoryEventArgs> ItemAdded;
    public event EventHandler<InventoryEventArgs> ItemUsed;
    public event EventHandler<InventoryEventArgs> ItemRemoved;

    List<IInventoryItem> items = new List<IInventoryItem>();

    public void addItem(IInventoryItem item)
    {
        items.Add(item);
        item.onPickup();

        Debug.Log("item picked up");

        ItemAdded?.Invoke(this, new InventoryEventArgs(item));

    }

    public void useItem(IInventoryItem item)
    {
        Debug.Log("inventory useItem" + item.itemName);

        ItemUsed?.Invoke(this, new InventoryEventArgs(item));
    }
    public void removeItem(IInventoryItem item)
    {
        items.Remove(item);

        ItemRemoved?.Invoke(this, new InventoryEventArgs(item));
    }
}
