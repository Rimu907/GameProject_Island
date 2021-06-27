using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cannondoorbreak : MonoBehaviour
{

    public Transform breakTransform;
    public Transform breakTransform1;
    public GameObject breakEffect;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "CannonBullet")
        {
            Sound.Playwallbreak();
            Instantiate(breakEffect, breakTransform.position, Quaternion.identity);
            Instantiate(breakEffect, breakTransform1.position, Quaternion.identity);
            DestroyObject(gameObject);
        }

        

    }
}
