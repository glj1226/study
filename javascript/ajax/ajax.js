/**
 *
 *  封装ajax 
 *  data格式: {name:'glj',age:18} 被转为--->name=glj&age=18
 *            {aa:['a1','a2','a3']} --->aa=a1&aa=a2&aa=a3
 *  ajax使用:
 *      Ajax.request('url',{
 *          data: xxx,
 *          success:function(xhr){...},
 *          failure:function(xhr){...}
 *      }
 *          
 *
 *
 *      );
 */
Ajax    =   function(){

     function   request(url,opt){
        function    fn(){}
        var async   =   opt.async   !== false,
            method  =   opt.method  ||  'GET',
            encode  =   opt.encode  ||  'UTF-8',
            data    =   opt.data    ||  null,
            success =   opt.success ||  fn,
            failure =   opt.failure ||  fn;
        method  =   method.toUpperCase();
        if(data &&  typeof  data    ==  'object'){

            data    =   transToFormat(data);
        }
        if(method   ==  'GET'   &&  data){
            url +=  (url.indexOf('?')   ==  -1? '?':'&')    +   data;
            data    =   null;
        }
        var xhr =   window.XMLHttpRequest   ?   new   XMLHttpRequest()  :   new ActiveXObject('Microsoft.XMLHTTP');
        xhr.onreadystatechange  =   function(){
            onStateChangeCallback(xhr,success,failure);
        };
        xhr.open(method,url,async);
        if(method   ==  'POST'){
            xhr.setRequestHeader('Content-type','application/x-www-form-urlencoded;charset='+encode);
        }
        xhr.send(data);
        return  xhr;
    }


    /*格式化数据成字符串*/
     /**
      * {'k1':'val1','k2':'val2'}=>k1=val1&k2=val2
      * {'key':[val1,val2,val3]}=>
      * key0=val1&key1=val2&key2=val3
      *
      *
      */
    function    transToFormat(obj){
        var temp    =   [];
        for(var key in  obj){
            var val =   obj[key];
            if(val.constructor  ==  Array){
                for(var i=0,    len=val.length; i<len;  i++){
                    temp.push(key+i+  '=' +   encodeURIComponent(val[i]))
                }
            }
            else
            {
                temp.push(key+  '=' +   encodeURIComponent(val));
            }
        }
        return  temp.join('&');
    }
    function    onStateChangeCallback(xhr,success,failure){
        if(xhr.readyState   ==  4){
            if(xhr.status>=200  &&  xhr.status  <   300)
            {
                success(xhr);
            }
            else
            {
                failure(xhr);
            }
        }
    
    }
    
    return  {request:request};
}();
