using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemInteractor : MonoBehaviour
{
    void Start()
    {

    }
    void Update()
    {

    }

    public Inventory inventory;

    private void OnControllerColliderHit(ControllerColliderHit hit)
    {
        IInventoryItem item = hit.gameObject.GetComponent<IInventoryItem>();
        if (item != null)
        {
            inventory.addItem(item); // where inventory is the inventory object ref
        }
    }
}
