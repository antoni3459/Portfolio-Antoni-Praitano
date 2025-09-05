using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UtilsPerso
{
    public static T Cast<T>(MonoBehaviour _obj) where T : MonoBehaviour
    {
        return (T)_obj;
    }

}
