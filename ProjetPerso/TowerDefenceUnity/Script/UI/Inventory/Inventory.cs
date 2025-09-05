


using System;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

using UnityEngine.UI;
public class Inventory : MonoBehaviour
{
    [SerializeField] List<Button> button = null;
    int indexButton = 0;
    
    public List<Button> Button { get => button; set => button = value;}
    public int IndexButton { get => indexButton; set => indexButton = value;}

    void Start()
    {
        
    }

    void Update()
    {
        
    }
    public void AddItem( )
    {
        
    }
}