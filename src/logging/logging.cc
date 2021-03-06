// Copyright (C) 2016 Zhe Wang <0x1998@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
#include <ni/logging/logging.hh>
#include <ni/logging/log_service.hh>

namespace ni
{
namespace logging
{
LogService* service_instance = nullptr;

LogService* init(size_t queue_size)
{
  if (service_instance)
    delete service_instance;
  service_instance = new LogService(queue_size);
  return service_instance;
}

LogService* service()
{
  return service_instance;
}

Logger* logger(const std::string& name)
{
  return service_instance ? service_instance->get(name) : nullptr;
}

void start()
{
  assert(service_instance);
  service_instance->start();
}

void stop()
{
  assert(service_instance);
  service_instance->stop();
}

} // namespace logging
} // namespace ni
