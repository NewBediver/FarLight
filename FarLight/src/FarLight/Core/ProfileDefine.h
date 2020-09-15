#pragma once

#if FL_PROFILE
#   define FL_PROFILE_BEGIN_SESSION(name, filepath) ::FarLight::Instrumentor::GetInstance().BeginSession(name, filepath)
#   define FL_PROFILE_END_SESSION()                 ::FarLight::Instrumentor::GetInstance().EndSession()
#   define FL_PROFILE_SCOPE(name)                   ::FarLight::InstrumentationTimer timer##__LINE__(name);
#   define FL_PROFILE_FUNCTION()                    FL_PROFILE_SCOPE(FL_FUNC_SIG)
#else
#   define FL_PROFILE_BEGIN_SESSION(name, filepath)
#   define FL_PROFILE_END_SESSION()
#   define FL_PROFILE_SCOPE(name)
#   define FL_PROFILE_FUNCTION()
#endif
