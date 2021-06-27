using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class treebroke : MonoBehaviour
{
    public GameObject stickeff;
    public Transform transform1;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    [System.Obsolete]
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "PlayerBullet")
        {
            Instantiate(stickeff, transform1.position, Quaternion.identity);
            DestroyObject(gameObject);

        }

        

    }
}
