using Firebase.Extensions;
using Firebase.Firestore;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using Unity.Android.Gradle.Manifest;
using UnityEngine;

public class DataFire :Singleton<DataFire>
{
	FirebaseFirestore fireStore = null;
	CollectionReference playerData = null;

	private void Start()
	{
		fireStore = FirebaseFirestore.DefaultInstance;
		playerData = fireStore.Collection(UtilsFireBase.PLAYER_DATA);
	}

	public void SignUpNewPlayer(string _userName, string _password, Action<bool> _OnRequest)
	{
		bool _isSuccess = false;

		playerData.GetSnapshotAsync().ContinueWithOnMainThread(_task =>
		{
			QuerySnapshot _snapShot = _task.Result;
			List<DocumentSnapshot> _allDocument = _snapShot.Documents.ToList();
			foreach (DocumentSnapshot _document in _allDocument)
			{
				if (_document.ToDictionary()[UtilsFireBase.USERNAME].ToString() == _userName)
				{
					_isSuccess = false;
					_OnRequest?.Invoke(_isSuccess);
					return;
				}
			}
			_isSuccess = true;
			CreateDoc(_userName,_password);
			_OnRequest?.Invoke(_isSuccess);
		});
	}

	private void CreateDoc(string _userName, string _password)
	{
		DocumentReference _doc = playerData.Document();
		_doc.SetAsync(new Dictionary<string, string> { { UtilsFireBase.USERNAME, _userName }, { UtilsFireBase.PASSWORD, _password } });
	}

	public void LoginPlayer(string _userName, string _password, Action<bool> _OnRequest)
	{
		bool _isSuccess = false;
		playerData.GetSnapshotAsync().ContinueWithOnMainThread(_task =>
		{
			QuerySnapshot _snapShot = _task.Result;
			List<DocumentSnapshot> _allDocument = _snapShot.Documents.ToList();
			foreach (DocumentSnapshot _document in _allDocument)
			{
				if (_document.ToDictionary()[UtilsFireBase.USERNAME].ToString() == _userName && _document.ToDictionary()[UtilsFireBase.PASSWORD].ToString() == _password)
				{
					_isSuccess = true;
					_OnRequest?.Invoke(_isSuccess);
					return;
				}
			}
			_isSuccess = false;
			_OnRequest?.Invoke(_isSuccess);
		});
	}
}
