import React, { useState, useEffect, useRef } from 'react';

function Login() {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [count, setCount] = useState(0);
  const [start, setStart] = useState(false);
  const [tik, setTik] = useState(0);

  const inputRef = useRef(null);
  const passwordRef = useRef(null);
  useEffect(()=>{
    if (passwordRef.current) {
      passwordRef.current.focus();
    }
  },[]);//

  useEffect(() => {
    if (inputRef.current) {
      inputRef.current.focus();
    }
  }, []);// 

  const handleSubmit = (e) => {
    e.preventDefault();
    console.log("Email:", email);
    console.log("Password:", password);
  };

  useEffect(() => {
    if (!start) return;
    const interval = setInterval(() => {
      setCount(prev => prev + 1);
    }, 1000);
    return () => clearInterval(interval);
  }, [start]);

  return (
    <div className="flex items-center justify-center min-h-screen bg-gray-100">
      <div className="w-full max-w-md p-8 space-y-6 bg-white rounded shadow">
        <h2 className="text-2xl font-bold text-center text-gray-800">Login</h2>
        <form className="space-y-4" onSubmit={handleSubmit}>
          <div>
            <label className="block mb-1 text-sm font-medium text-gray-700">
              Email
            </label>
            <input
              type="email"
              className="w-full px-3 py-2 border rounded focus:outline-none focus:ring-2 focus:ring-blue-400"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              ref={inputRef}
              required
              autoComplete="username"
            />
          </div>
          <div>
            <label className="block mb-1 text-sm font-medium text-gray-700">
              Password
            </label>
            <input
              type="password"
              className="w-full px-3 py-2 border rounded focus:outline-none focus:ring-2 focus:ring-blue-400"
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              ref={passwordRef}
              required
              autoComplete="current-password"
            />
          </div>
          <div className="flex justify-center">
            <button
              type="submit"
              onClick={handleSubmit}
              className="px-4 py-2 font-semibold text-white bg-blue-600 rounded hover:bg-blue-700 transition"
            >
              Login
            </button>
          </div>
        </form>
      </div>

      <div className="absolute bottom-0 left-0 w-full p-4 text-center text-gray-600">
        <button onClick={() => {
          setStart(true);
          setTik(prev => prev + 1);
        }} className="block mx-auto my-3 px-4 py-2 font-semibold text-white bg-blue-600 rounded hover:bg-blue-700 transition">
          start
        </button>
        <button onClick={() => setStart(false)} className="block my-3 mx-auto px-4 py-2 font-semibold text-white bg-red-600 rounded hover:bg-red-700 transition">
          stop
        </button>
        <button onClick={() => {
          setCount(0);
          setStart(false);
        }} className="my-3 mx-auto block px-4 py-2 font-semibold text-white bg-red-600 rounded hover:bg-red-700 transition">
          reset
        </button>
        <p className="py-4 bg-amber-200 w-md">{count}</p>
        <p className='text-sm'>Start clicked: {tik}</p>
      </div>
    </div>
  );
}

export default Login;
