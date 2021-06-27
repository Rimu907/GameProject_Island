using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Hud : MonoBehaviour
{
    public Inventory inventory;

    // Start is called before the first frame update
    void Start()
    {
        inventory.ItemAdded += InventoryItemAdded;
        inventory.ItemRemoved += InventoryItemRemoved;
    }

    private void InventoryItemAdded(object sender, InventoryEventArgs e)
    {
        Debug.Log("HUD notified about item" + e.item.itemName);

        Transform panel = transform.Find("InventoryHud");
        foreach (Transform slot in panel)
        {
            Image image = slot.GetComponent<Image>();
            InventoryItemClickable button = slot.GetComponent<InventoryItemClickable>();


            if (!image.enabled)
            {
                image.enabled = true;
                image.sprite = e.item.itemImage;
                button.item = e.item;
                break;
            }
        }
    }

    private void InventoryItemRemoved(object sender, InventoryEventArgs e)
    {
        Transform panel = transform.Find("InventoryHud");
        foreach (Transform slot in panel)
        {
            Image image = slot.GetComponent<Image>();
            InventoryItemClickable button = slot.GetComponent<InventoryItemClickable>();


            if (button.item == e.item)
            {
                image.enabled = false;
                image.sprite = null;
                button.item = null;
                break;
            }
        }
    }
}
