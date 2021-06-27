using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SaveDog : MonoBehaviour
{
    public GameObject door;
    
    



    //public Door doorObject;
    // Start is called before the first frame update

    private void OnTriggerEnter(Collider other)
    {
        //doorObject.Open();
        if (other.gameObject.tag == "crystal")
        {
            Sound.Playdoor();
            door.transform.position = door.transform.position + new Vector3(0, -10, 0);
            

        }

    }


}
