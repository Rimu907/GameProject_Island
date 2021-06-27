using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Switch : MonoBehaviour
{
    public GameObject door;
    public GameObject Dooreff;
    public Transform dooref1;



    //public Door doorObject;
    // Start is called before the first frame update

    private void OnTriggerEnter(Collider other)
    {
        //doorObject.Open();
        if (other.gameObject.tag == "crystal")
        {
            Sound.Playdoor1();
            door.transform.position = door.transform.position + new Vector3(0, 1, 0);
            Instantiate(Dooreff, dooref1.position, Quaternion.identity);

        }
        
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "crystal")
        {
            door.transform.position = door.transform.position - new Vector3(0, 1, 0);
            
        }

    }



}
