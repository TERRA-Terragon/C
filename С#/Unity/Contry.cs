using JetBrains.Annotations;
using OpenCover.Framework.Model;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.GlobalIllumination;
using UnityEngineInternal;
[System.Serializable]
public class Focus
{
    public string name;
    public int buf;
    public int day_for;
    public bool have;
    public string info;
}
[System.Serializable]
public class Politic
{
    List<Focus> focusList;
}
[System.Serializable]
public class Contry_c
{
    public string name="";
    public int people,id;
    public int polit, army_exp=0,stability=100, pepolpe_need_war=0;
    public string stolitsa;
    public List<GameObject> army;
    public List<teritory> have;
}
[System.Serializable]
public class recource
{
    static string[] all ={ "gold", "copper", "iron", "tungsten" };//"gold", "copper", "iron", "tungsten"
    public string name="";
    public int count=0;
}
[System.Serializable]
public class teritory
{
    public string name;
    public int id;
    public recource[] rc; 
}
public class Contry : MonoBehaviour
{
    [Header("Contry")]
    public Contry_c yo_c;
    [Header("Foreign policy")]//внешняя
    public Politic pol;
    [Header("Territory:")]
    public List<teritory> you;
    int ttt = 0;

    void Start()
    {
        Debug.Log(""+ you);
       // string path
    }

    void Update()
    {
        
    }
    void FixedUpdate()
    {

    }
    IEnumerator tttt() { 
        yield return new WaitForSeconds(1f);
    }

}
