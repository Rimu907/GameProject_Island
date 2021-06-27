using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShootController : MonoBehaviour
{

    public float fireRate = 0.5f;
    private float nextFire = 0.0f;
    public GameObject shot;
    public Transform shotTransform;
 
    public GameObject Gunfire;
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
        

        if (Input.GetButton("Fire1") && Time.time > nextFire )
        {
            nextFire = Time.time + fireRate;
            Sound.Playgun();
            Instantiate(Gunfire, shotTransform.position, Quaternion.identity);
            Instantiate(shot, shotTransform.position, Camera.main.transform.rotation);
        }
        

    }
}
