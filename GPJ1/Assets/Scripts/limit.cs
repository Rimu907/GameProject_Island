using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class limit : MonoBehaviour
{
    public int limittime = 1;
    // Start is called before the first frame update
    void Start()
    {
        Destroy(gameObject,limittime); 
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
