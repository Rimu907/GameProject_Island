using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bridgeswitch : MonoBehaviour
{
    public GameObject bridgesupport;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void OnTriggerEnter(Collider other)
    {
        //doorObject.Open();
        if (other.gameObject.tag == "stone")
        {
            Sound.Playdoor1();
            bridgesupport.transform.position = bridgesupport.transform.position + new Vector3(0, 0, -10);
            
        }

    }
    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "stone")
        {
            Sound.Playdoor1();
            bridgesupport.transform.position = bridgesupport.transform.position + new Vector3(0, 0, +10);
            
            
        }

    }
}
