 

namespace AHIni
{
    bool GetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        CString& str_value,
        int buffer_length /*= 1000*/) const
    {
        assert(str_filename_.GetLength() > 0);

        CString str_default = TEXT("NotExist");		//如果找不到对应的键，就返回该值
        CString str_temp;

        DWORD dw_characters = ::GetPrivateProfileString(str_fieldname,
            str_keyname,
            str_default,
            str_temp.GetBuffer(buffer_length),
            buffer_length,
            str_filename_);
        str_temp.ReleaseBuffer();

        //注意GetPrivateProfileString函数返回错误的形式
        if (str_temp.Compare(str_default) == 0)
        {
            return false;
        }
        else
        {
            str_value = str_temp;
            return true;
        }
    }


    bool GetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        int& n_value) const
    {
        CString str_value = TEXT("");
        if (GetValueOfKey(str_fieldname, str_keyname, str_value))
        {
            n_value = _ttoi(str_value);
            return true;
        }
        else
        {
            return false;
        }
    }


    bool GetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        byte& byte_value) const
    {
        CString str_value = TEXT("");
        if (GetValueOfKey(str_fieldname, str_keyname, str_value))
        {
            byte_value = (byte)(_ttoi(str_value));
            return true;
        }
        else
        {
            return false;
        }
    }


    bool GetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        bool& b_value) const
    {
        CString str_value = TEXT("");
        if (GetValueOfKey(str_fieldname, str_keyname, str_value))
        {
            b_value = (bool)(_ttoi(str_value) == 1);
            return true;
        }
        else
        {
            return false;
        }
    }


    bool GetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        double& d_value) const
    {
        CString str_value = TEXT("");
        if (GetValueOfKey(str_fieldname, str_keyname, str_value))
        {
            //d_value = _ttof(str_value);
            TCHAR* sz_stop = NULL;
            d_value = _tcstod(str_value, &sz_stop);
            return true;
        }
        else
        {
            return false;
        }
    }


    bool SetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        const TCHAR* str_value)
    {
        //防止在调用函数前str_filename_未被初始化
        if (str_filename_.IsEmpty())
        {
            AfxMessageBox(TEXT("在调用函数SetValueOfKey时，str_filename_未被赋值，异常退出"));
            return false;
        }

        BOOL b_ret = ::WritePrivateProfileString(str_fieldname,
            str_keyname,
            str_value,
            str_filename_);

        if (b_ret)
            return true;
        else
            return false;
    }


    bool SetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        int n_value)
    {
        CString str_value = TEXT("");
        str_value.Format(TEXT("%d"), n_value);
        return SetValueOfKey(str_fieldname, str_keyname, str_value);
    }

    bool SetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        byte byte_value)
    {
        CString str_value = TEXT("");
        str_value.Format(TEXT("%u"), byte_value);
        return SetValueOfKey(str_fieldname, str_keyname, str_value);
    }


    bool SetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        bool b_value)
    {
        CString str_value = TEXT("");
        str_value.Format(TEXT("%d"), b_value);
        return SetValueOfKey(str_fieldname, str_keyname, str_value);
    }


    bool SetValueOfKey(const TCHAR* str_fieldname,
        const TCHAR* str_keyname,
        double d_value,
        int decimal_places /*= 2*/)
    {
        assert(decimal_places >= 0);
        CString str_format = TEXT("");
        str_format.Format(TEXT("%%0.%df"), decimal_places);

        CString str_value = TEXT("");
        str_value.Format(str_format, d_value);
        return SetValueOfKey(str_fieldname, str_keyname, str_value);

    }
}
