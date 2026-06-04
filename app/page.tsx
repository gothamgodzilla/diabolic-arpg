'use client';
import React from 'react';

export default function DiabolicLanding() {
  return (
    <div className="min-h-screen bg-black text-white overflow-hidden">
      <div className="relative h-screen flex items-center justify-center bg-[radial-gradient(at_center,#4B0082_0%,#000_70%)]">
        <div className="text-center z-10">
          <h1 className="text-8xl font-bold tracking-tighter mb-4 text-transparent bg-clip-text bg-gradient-to-r from-purple-500 via-red-500 to-orange-500 animate-pulse">DIABOLIC</h1>
          <p className="text-3xl mb-8">OLYMPUS CORRUPTION PROTOCOL</p>
          <p className="text-xl mb-12 max-w-2xl mx-auto">Slay Gods. Farm DIABO Nodes. Become the Tycoon.</p>
          <div className="flex gap-6 justify-center">
            <button className="px-12 py-6 bg-red-600 hover:bg-red-700 text-2xl font-bold rounded-xl border-4 border-orange-400 transition-all">ENTER THE HELLS</button>
            <button className="px-12 py-6 border-4 border-purple-500 hover:bg-purple-950 text-2xl font-bold rounded-xl transition-all">DEPLOY NODE</button>
          </div>
          <div className="mt-16 text-sm opacity-70">SYSTEM CORRUPTION: 94% • DIABO YIELD: LIVE</div>
        </div>
      </div>
      <div className="p-20 bg-zinc-950">
        <h2 className="text-5xl text-center mb-12">NODE FARMING EMPIRE</h2>
        <div className="grid grid-cols-3 gap-8 max-w-6xl mx-auto">
          {['Common', 'Epic', 'God-Tier'].map((tier, i) => (
            <div key={i} className="bg-zinc-900 border border-purple-500 p-8 rounded-3xl text-center hover:scale-105 transition">
              <div className="text-4xl mb-4">{tier}</div>
              <div className="text-6xl font-mono mb-2">1,240 DIABO</div>
              <div className="text-sm opacity-60">/24h • Offline Accrual Active</div>
              <button className="mt-8 w-full py-4 bg-gradient-to-r from-purple-600 to-red-600 rounded-xl">UPGRADE NODE</button>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}
