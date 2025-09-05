using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[Serializable]
public class CustomDico<TKey, TValue>
{
	[SerializeField] List<StructDictionary<TKey, TValue>> dico = new();
	public TValue this[TKey _key] => GetValue(_key);

	public TValue GetValue(TKey _key)
	{
        for (int i = 0; i < dico.Count; i++)
        {
            if(dico[i].Key.Equals(_key))
				return dico[i].Value;
        }
		return default(TValue);
    }

	public void Add(TKey _key, TValue _value)
	{
		if (ContainKey(_key))
		{
			Debug.LogError(_key.ToString() + "Contain in Dico");
			return;
		}
		dico.Add(new StructDictionary<TKey, TValue>() {Key = _key, Value = _value } );
	}

	public bool ContainKey(TKey _key)
	{
        for (int i = 0; i < dico.Count; i++)
        {
            if(dico[i].Key.Equals(_key))
				return true;
        }
		return false;
    }

	public void RemoveAtKey(TKey _key)
	{
		for (int i = 0; i < dico.Count; i++)
		{
			if (dico[i].Key.Equals(_key))
			{
				dico.RemoveAt(i);
				return;
			}
		}
    }
}

[Serializable]
struct StructDictionary<TKey, TValue>
{
	[SerializeField] TKey key;
	[SerializeField] TValue tValue;

	public TKey Key { get => key; set => key = value; }
	public TValue Value { get => tValue; set => tValue = value; } 
}
