using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CannonController : MonoBehaviour
{

    public float fireRate1 = 0.5f;
    private float nextFire1 = 0.0f;
    public GameObject shot1;
    public Transform shotTransform1;
    public GameObject gunfire;
    
    //float y = 0.0f;
    // Start is called before the first frame update
    void Start()
    {


    }

    // Update is called once per frame
    public void Plus()
    {
        
    }



    void Update()
    {
        

        //if (Input.GetButton("Fire1") && Time.time > nextFire1)
        //{
        //    nextFire1 = Time.time + fireRate1;
        //    Instantiate(shot1, shotTransform1.position, shotTransform1.rotation);
        //}


    }
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "CannonBullet" && Time.time > nextFire1)
        {
            nextFire1 = Time.time + fireRate1;
            Sound.Playcannon();
            Instantiate(gunfire, shotTransform1.position, shotTransform1.rotation);
            Instantiate(shot1, shotTransform1.position, shotTransform1.rotation);
            
        }


    }
}
